#ifndef MAP_H
# define MAP_H

#include "libft.h"
#include <stdint.h>
#include <sys/mman.h>
#include <signal.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <limits.h>

# define MAP_LEN 8
# define MAP_SIZE sizeof (t_cell) * (MAP_LEN * MAP_LEN)

typedef struct	s_cell {
	uint32_t	team_id;
	pid_t		pid;
	uint8_t		team_leader; // process that will sent target to other
	uint32_t	ennemy; // pid
	uint8_t		ennemy_set;
}				t_cell;

typedef struct	s_msgbuf {
	long		mtype;
	char		mtext[255];
}				t_msgbuf;

typedef struct	s_inc {
	size_t		i;
	size_t		j;
	size_t		k;
}				t_inc;

typedef struct	s_coord {
	size_t		x;
	size_t		y;
}				t_coord;

#endif
