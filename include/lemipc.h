#ifndef LEMIPC_H
# define LEMIPC_H

#include "map.h"
#include <assert.h>
#define DBG 0

typedef struct	s_data {
	uint32_t	team_id;
	pid_t 		pid;
	void		*map_mem;
	t_cell		cells[MAP_LEN][MAP_LEN];
	sem_t		*sem;
	int			msgq_id;
	t_msgbuf	msgbuf;
	uint8_t		gameLaunched:1;
}				t_data;

extern t_data	g_data;

void		get_args(int ac, char **av);
void		sighandle();
void		map_init();
void		map_fill();
void		map_addplayer();
void		map_get();
void		move_player();
int			print_cells();
int			playersPlayed();
uint32_t	playersPlayedNb();
void		msgq_getid();
int			teamleader_exist();
void		ressources_erase();
void		playersResetPlayed();
t_enemy		enemy_chr(t_cell current);
t_cell 		nearestPosToEnemy(t_cell current);
void		set_currentval(t_cell current);
void		set_to_enemyval(t_cell current);
void		reset_cells_val();
int			enemies_alive();
int			oneTeamAlive();
uint32_t	playersNb();
void		set_newenemy_pos(t_cell newPos);
void		map_currentcell(t_cell **current_cell);
int			allyNearEnemy();
void		ally_clear_enemyset();
int			two_enemies_near();
void		send_target(t_enemy enemy);

#endif
