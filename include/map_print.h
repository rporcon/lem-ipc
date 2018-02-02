#ifndef PRINT_MAP_H
# define PRINT_MAP_H

#include "map.h"
#define DBG 0

typedef struct	s_players {
	/* uint8_t		played; */
	uint32_t	pid;
}				t_players;

typedef struct	s_gamedata {
	uint32_t	players_nb;
	t_players	*players;
	key_t		key;
	int			msgq_id;
	t_msgbuf	msgbuf;
}				t_gamedata;

void    	players_move(t_gamedata *gdata, void *map_mem,
			t_cell cells[MAP_LEN][MAP_LEN]);
void		players_get(t_players *players, t_cell cells[MAP_LEN][MAP_LEN]);
uint32_t	players_getnb(t_cell cells[MAP_LEN][MAP_LEN]);
void		map_fill(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN]);
void		map_print(t_cell cells[MAP_LEN][MAP_LEN], int type);


#endif
