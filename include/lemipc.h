#ifndef LEMIPC_H
# define LEMIPC_H

#include "map.h"
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct	s_data {
	size_t		team_id;
}				t_data;

typedef struct	s_msgbuf {
	long		mtype;
	char		mtext[255];
}				t_msgbuf;

extern t_data	g_data;

void	get_args(int ac, char **av);
void	sighandle();
void	map_init();
void	map_fill(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN]);
void	map_addplayer(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN]);
void	map_get(void **map_mem);
void	msgq_getid(int *msgid);
void	ressources_erase();

#endif
