#ifndef LEMIPC_H
# define LEMIPC_H

#include "map.h"

typedef struct	s_data {
	uint32_t	team_id;
}				t_data;

extern t_data	g_data;

// use globals for sem, shm (to open only once / avoid pass through every func)

void	get_args(int ac, char **av);
void	sighandle();
void	map_init();
void	map_fill(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN]);
void	map_addplayer(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN]);
void	map_get(void **map_mem);
void	msgq_getid(int *msgid);
void	ressources_erase();

#endif
