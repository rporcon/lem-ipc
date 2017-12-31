#ifndef LEMIPC_H
# define LEMIPC_H

#include "libft.h"
#include <poll.h>
#include <stdint.h>
#include <sys/mman.h>
#include <signal.h>
#include <semaphore.h>

# define MAP_LEN 8
# define MAP_SIZE sizeof (t_cell) * (MAP_LEN * MAP_LEN)

typedef struct	s_cell {
	size_t		team_id;
	uint32_t	pid;
}				t_cell;

typedef struct	s_inc {
	size_t		i;
	size_t		j;
	size_t		k;
}				t_inc;

typedef struct	s_coord {
	size_t		x;
	size_t		y;
}				t_coord;

typedef struct	s_data {
	size_t		team_id;
}				t_data;

extern t_data	g_data;

void	get_args(int ac, char **av);
void	sighandle();
int		map_init(void **map_mem);
void	map_erase();
void	map_read(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN]);
void	map_addplayer(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN]);
void	map_get(void **map_mem);
void	map_print(t_cell cells[MAP_LEN][MAP_LEN]);
int		cells_cmp(t_cell cells1[MAP_LEN][MAP_LEN],
			t_cell cells2[MAP_LEN][MAP_LEN]);

#endif
