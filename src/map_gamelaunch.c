/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gamelaunch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:56:43 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/03 18:56:44 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_print.h"

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
