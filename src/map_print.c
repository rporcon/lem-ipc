/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:42:05 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/02 17:07:04 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_print.h"

t_gamedata	g_data;

void	map_get(void **map_mem)
{
	int		fd;

	if (MAP_LEN < 3 || MAP_LEN > 200)
		err_exit("MAP_SIZE invalid size (too large or too small)", 1);
	while (1)
	{
		if ((fd = shm_open("/shm-lemipc_map", O_RDONLY, 0644)) != -1)
			break ;
		sleep(1);
	}
	if ((*map_mem = mmap(NULL, next_powerchr(MAP_SIZE, getpagesize()),
			PROT_READ, MAP_SHARED, fd, 0)) == MAP_FAILED)
		perr_exit("map_get mmap");
	close(fd);
}

void	map_fill(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN])
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof(inc));
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			cells[inc.i][inc.j] = ((t_cell *)map_mem)[inc.k];
			inc.j++;
			inc.k++;
		}
		inc.i++;
	}
}

void	map_print(t_cell cells[MAP_LEN][MAP_LEN], int type)
{
	t_inc			inc;

	if (g_data.keep_map == 0)
		system("clear");
	ft_memset(&inc, 0, sizeof(inc));
	printf("--------------------------------\n");
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (cells[inc.i][inc.j].team_id == 0)
				printf("o");
			else
				printf("%u", cells[inc.i][inc.j].team_id);
			printf("   ");
			fflush(stdout);
			inc.j++;
		}
		printf("\n\n");
		inc.i++;
	}
	printf("--------------------------------\n");
	if (type == 1)
		printf("Press enter to launch the game\n");
}

void	game_init(t_cell cells[MAP_LEN][MAP_LEN])
{
	g_data.players_nb = players_getnb(cells);
	if ((g_data.players = calloc(g_data.players_nb + 1, sizeof(t_players)))
			== NULL)
		perr_exit("game_init calloc");
	players_get(g_data.players, cells);
	if ((g_data.key = ftok("./src/msg.c", '*')) == -1)
		perr_exit("game_init ftok");
	if ((g_data.msgq_id = msgget(g_data.key, 0644)) == -1)
		perr_exit("game_init msgget");
	fcntl(0, F_SETFL, fcntl(0, F_GETFL) & ~(O_NONBLOCK));
}

void	game_launch(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN])
{
	char			enter[8];

	ft_memset(&g_data.msgbuf, 0, sizeof(g_data.msgbuf));
	read(0, enter, sizeof(enter));
	if (enter[0] == '\n')
	{
		game_init(cells);
		while (1)
		{
			printf("Press enter to play one turn\n");
			ft_memset(enter, 0, sizeof(enter));
			fgets(enter, sizeof(enter), stdin);
			if (enter[0] == '\n')
				players_move(map_mem, cells);
			g_data.players_nb = players_getnb(cells);
			players_get(g_data.players, cells);
		}
	}
}

int		main(int ac, char **av)
{
	void			*map_mem;
	t_cell			cells[MAP_LEN][MAP_LEN];
	t_cell			cells_tmp[MAP_LEN][MAP_LEN];

	get_args(ac, av);
	map_mem = NULL;
	ft_memset(cells, 0, MAP_SIZE);
	map_get(&map_mem);
	map_fill(map_mem, cells);
	map_print(cells, 1);
	fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);
	while (1)
	{
		ft_memcpy(cells_tmp, cells, MAP_SIZE);
		map_fill(map_mem, cells);
		if (ft_memcmp(cells_tmp, cells, MAP_SIZE) != 0)
			map_print(cells, 1);
		game_launch(map_mem, cells);
		sleep(1);
	}
	return (0);
}
