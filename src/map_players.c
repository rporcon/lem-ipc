/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:10:41 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/02 15:16:22 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_print.h"

void		players_get(t_players *players, t_cell cells[MAP_LEN][MAP_LEN])
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof(inc));
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (cells[inc.i][inc.j].team_id > 0)
			{
				players[inc.k].pid = cells[inc.i][inc.j].pid;
				inc.k++;
			}
			inc.j++;
		}
		inc.i++;
	}
}

uint32_t	players_getnb(t_cell cells[MAP_LEN][MAP_LEN])
{
	t_inc			inc;
	uint32_t		players_nb;

	ft_memset(&inc, 0, sizeof(inc));
	players_nb = 0;
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (cells[inc.i][inc.j].team_id > 0)
				players_nb++;
			inc.j++;
		}
		inc.i++;
	}
	return (players_nb);
}

uint32_t	lastteam_alive_name(t_cell cells[MAP_LEN][MAP_LEN])
{
	t_inc			inc;
	uint32_t		team_id;

	ft_memset(&inc, 0, sizeof(inc));
	team_id = 0;
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (cells[inc.i][inc.j].team_id > 0)
			{
				team_id = cells[inc.i][inc.j].team_id;
				inc.i = MAP_LEN;
				break ;
			}
			inc.j++;
		}
		inc.i++;
	}
	return (team_id);
}

void		players_move(t_gamedata *gdata, void *map_mem,
				t_cell cells[MAP_LEN][MAP_LEN])
{
	size_t	i;

	i = 0;
	while (i < players_getnb(cells))
	{
		gdata->msgbuf.mtype = (long)INT_MAX + gdata->players[i].pid;
		if (msgsnd(gdata->msgq_id, &gdata->msgbuf,
				sizeof(gdata->msgbuf.mtext), 0) == -1)
			perr_exit("players_move msgsnd");
		sleep(1);
		i++;
	}
	DBG == 1 ? printf("sdmsg to %d players\n", players_getnb(cells)) : (void)0;
	gdata->msgbuf.mtype = INT_MAX;
	if (msgrcv(gdata->msgq_id, &gdata->msgbuf, sizeof(gdata->msgbuf.mtext),
			gdata->msgbuf.mtype, 0) == -1)
		perr_exit("players_move msgrcv");
	DBG == 1 ? printf("turn finished\n") : (void)0;
	map_fill(map_mem, cells);
	map_print(cells, 0);
	if (ft_strcmp(gdata->msgbuf.mtext, "EndOfGame") == 0)
	{
		printf("[End of game]\nteam %u won !\n", lastteam_alive_name(cells));
		exit(0);
	}
}
