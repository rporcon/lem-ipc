#ifndef LEMIPC_H
# define LEMIPC_H

#include "map.h"

typedef struct	s_data {
	size_t		team_id;
}				t_data;

extern t_data	g_data;

void	get_args(int ac, char **av);
void	sighandle();
int		map_init(void **map_mem);
void	map_erase();
void	map_fill(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN]);
void	map_addplayer(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN]);
void	map_get(void **map_mem);
void	map_print(t_cell cells[MAP_LEN][MAP_LEN]);

#endif
