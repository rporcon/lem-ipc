#ifndef LEMIPC_H
# define LEMIPC_H

#include "map.h"
#include <assert.h>

typedef struct	s_data {
	uint32_t	team_id;
	pid_t 		pid;
	void		*map_mem;
	t_cell		cells[MAP_LEN][MAP_LEN];
	sem_t		*sem;
	int			msgq_id;
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
void		setCurrentVal(t_cell current);
void		setToEnemyVal(t_cell current);
void		resetCellsVal();
int			enemiesAlive();
int			oneTeamAlive();
uint32_t	playersNb();
void		setNewEnemyPos(t_cell newPos);
void		map_currentcell(t_cell **current_cell);
int			allyNearEnemy();
void		allyClearEnemySet();
int			twoEnemiesNear();
void		send_target(t_enemy enemy);

#endif
