#ifndef PRINT_MAP_H
# define PRINT_MAP_H

#include "map.h"

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

#endif
