#ifndef LEMIPC_H
# define LEMIPC_H

#include "libft.h"
#include <stdint.h>
#include <sys/mman.h>

# define MAP_LEN 8
# define MAP_SIZE MAP_LEN * MAP_LEN

typedef struct	s_cell {
	size_t		team_id;
	uint32_t	pid;
}				t_cell;

typedef struct	s_inc {
	size_t		i;
	size_t		j;
	size_t		k;
}				t_inc;

typedef struct	s_opt {
	size_t		teamid;
}				t_opt;

extern t_opt	g_opt;

void	get_args(int ac, char **av);

#endif
