/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:56:35 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/09 18:39:16 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	map_addplayer(void)
{
	t_coord		coords;

	if ((g_data.sem = sem_open("/sem-lemipc_map", 0)) == SEM_FAILED)
		perr_exit("map_addplayer sem_open");
	printf("Enter your coords (must be y, x) :\n");
	g_data.player_init = 1;
	get_coords(&coords);
	if (g_data.cells[coords.y][coords.x].team_id > 0)
	{
		munmap_map();
		err_exit("player already exist on this coord", 1);
	}
	g_data.cells[coords.y][coords.x].team_id = g_data.team_id;
	g_data.cells[coords.y][coords.x].pid = getpid();
	g_data.cells[coords.y][coords.x].x = coords.x;
	g_data.cells[coords.y][coords.x].y = coords.y;
	ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
	map_fill();
}

void	map_currentcell(t_cell **current_cell)
{
	t_inc		inc;

	ft_memset(&inc, 0, sizeof(inc));
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.pid == g_data.cells[inc.i][inc.j].pid)
			{
				*current_cell = &g_data.cells[inc.i][inc.j];
				return ;
			}
			inc.j++;
			inc.k++;
		}
		inc.i++;
	}
}

void	map_fill(void)
{
	t_inc			inc;

	if (DBG == 1)
		printf("----------------\n");
	ft_memset(&inc, 0, sizeof(inc));
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			g_data.cells[inc.i][inc.j] = ((t_cell *)g_data.map_mem)[inc.k];
			g_data.cells[inc.i][inc.j].y = inc.i;
			g_data.cells[inc.i][inc.j].x = inc.j;
			inc.j++;
			inc.k++;
		}
		inc.i++;
	}
}

void	players_quit(void)
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof(inc));
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].pid > 0
					&& g_data.cells[inc.i][inc.j].pid != g_data.pid)
			{
				if (kill(g_data.cells[inc.i][inc.j].pid, SIGTERM) == -1)
					kill(g_data.cells[inc.i][inc.j].pid, SIGKILL);
			}
			inc.j++;
		}
		inc.i++;
	}
}

void	ressources_erase(void)
{
	sem_t			*sem;
	int				msgq_id;
	key_t			key;

	players_quit();
	g_data.msgbuf.mtype = INT_MAX;
	ft_strcpy(g_data.msgbuf.mtext, "EndOfGame");
	msgsnd(g_data.msgq_id, &g_data.msgbuf, sizeof(g_data.msgbuf.mtext), 0);
	if (g_data.ressources_erase_opt == 0)
	{
		g_data.cells[0][0].map_quit = 1;
		ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
	}
	shm_unlink("/shm-lemipc_map");
	if ((sem = sem_open("/sem-lemipc_map", 0)) == SEM_FAILED && DBG == 1)
		perr_exit("ressources_erase sem_open");
	sem_unlink("/sem-lemipc_map");
	if ((key = ftok("./src/msg.c", '*')) == -1)
		perr_exit("ressources_erase ftok");
	if ((msgq_id = msgget(key, 0644)) == -1 && DBG == 1)
		perr_exit("ressources_erase msgget");
	msgctl(g_data.msgq_id, IPC_RMID, NULL);
	exit(0);
}
