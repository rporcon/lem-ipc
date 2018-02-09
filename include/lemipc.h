/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:05:32 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/09 18:54:29 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H

# include "map.h"
# include <assert.h>
# include <time.h>
# define DBG 0

typedef struct	s_data {
	uint32_t	team_id;
	pid_t		pid;
	void		*map_mem;
	t_cell		cells[MAP_LEN][MAP_LEN];
	sem_t		*sem;
	int			msgq_id;
	t_msgbuf	msgbuf;
	uint8_t		player_init:1;
	uint8_t		ressources_erase_opt:1;
	uint32_t	dbg_i;
}				t_data;

extern t_data	g_data;

void			get_args(int ac, char **av);
void			sighandle();
void			get_coords(t_coord *coords);
void			map_init();
void			map_fill();
void			map_addplayer();
void			map_get();
void			move_player();
int				print_cells();
int				players_played();
uint32_t		players_played_nb();
void			msgq_getid();
int				teamleader_exist();
void			munmap_map();
void			ressources_erase();
void			players_reset_played();
t_enemy			enemy_chr(t_cell current);
t_cell			nearest_pos_toenemy(t_cell current);
void			set_currentval(t_cell current);
void			set_to_enemyval(t_cell current);
void			reset_cells_val();
int				enemies_alive();
int				oneteam_alive();
uint32_t		players_nb();
void			set_newenemy_pos(t_cell new_pos);
void			map_currentcell(t_cell **current_cell);
int				ally_nearenemy();
void			ally_clear_tlenemyset();
int				two_enemies_near();
void			send_target(t_enemy enemy);
void			end_of_turn();
void			dbg_moveplayer(t_cell *current);

#endif
