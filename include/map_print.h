/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:09:26 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/02 15:10:21 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PRINT_H
# define MAP_PRINT_H

# include "map.h"
# define DBG 0

typedef struct	s_players {
	uint32_t	pid;
}				t_players;

typedef struct	s_gamedata {
	uint32_t	players_nb;
	t_players	*players;
	key_t		key;
	int			msgq_id;
	t_msgbuf	msgbuf;
}				t_gamedata;

void			players_move(t_gamedata *gdata, void *map_mem,
				t_cell cells[MAP_LEN][MAP_LEN]);
void			players_get(t_players *players, t_cell cells[MAP_LEN][MAP_LEN]);
uint32_t		players_getnb(t_cell cells[MAP_LEN][MAP_LEN]);
void			map_fill(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN]);
void			map_print(t_cell cells[MAP_LEN][MAP_LEN], int type);

#endif
