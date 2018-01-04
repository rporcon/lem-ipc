#ifndef LEMIPC_H
# define LEMIPC_H

#include "map.h"

typedef struct	s_data {
	uint32_t	team_id;
	void		*map_mem;
	t_cell		cells[MAP_LEN][MAP_LEN];
	sem_t		*sem;
	int			msgq_id;
}				t_data;

extern t_data	g_data;

void	get_args(int ac, char **av);
void	sighandle();
void	map_init();
void	map_fill();
void	map_addplayer();
void	map_get();
void	msgq_getid();
int		teamleader_exist();
void	ressources_erase();
void	map_currentcell(pid_t pid, t_cell **current_cell);
void	send_target();

#endif
