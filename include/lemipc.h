#ifndef LEMIPC_H
# define LEMIPC_H

#include "map.h"
#include <assert.h>

typedef struct	s_data {
	uint32_t	team_id;
	void		*map_mem;
	t_cell		cells[MAP_LEN][MAP_LEN];
	sem_t		*sem;
	int			msgq_id;
}				t_data;

extern t_data	g_data;

void		get_args(int ac, char **av);
void		sighandle();
void		map_init();
void		map_fill();
void		map_addplayer();
void		map_get();
int			print_cells();
int			playersPlayed();
size_t		playersPlayedNb();
void		msgq_getid();
int			teamleader_exist();
void		ressources_erase();
void		playersResetPlayed();
int			enemiesAlive();
uint32_t	playersNb(t_cell cells[MAP_LEN][MAP_LEN]);
void		setNewEnemyPos(pid_t pid, t_cell newPos);
void		map_currentcell(pid_t pid, t_cell **current_cell);
void		allyClearEnemySet(t_cell enemy);
void		send_target(t_cell *enemy);

#endif
