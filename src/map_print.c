#include "map_print.h"

void    map_get(void **map_mem)
{
	int     fd;

	while (1)
	{
		if ((fd = shm_open("/shm-lemipc_map", O_RDONLY, 0644)) != -1)
			break ;
		sleep (1);
	}
    if ((*map_mem = mmap(NULL, next_powerchr(MAP_SIZE, getpagesize()), PROT_READ
                , MAP_SHARED, fd, 0)) == MAP_FAILED)
    	perr_exit("map_get mmap");
    close(fd);
}

void	map_fill(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN])
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			cells[inc.i][inc.j] = ((t_cell *)map_mem)[inc.k];
			inc.j++;
			inc.k++;
		}
		inc.i++;
	}
}

void	map_print(t_cell cells[MAP_LEN][MAP_LEN], int type)
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof inc);
	ft_putstr("--------------------------------\n");
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (cells[inc.i][inc.j].team_id == 0)
				ft_putchar('o');
			else
				printf("%u", cells[inc.i][inc.j].team_id);
			fflush(stdout);
			ft_putstr("   ");
			inc.j++;
		}
		ft_putstr("\n\n");
		inc.i++;
	}
	ft_putstr("--------------------------------\n");
	if (type == 1)
			ft_putstr("Press enter to launch the game\n");
}

void	players_get(t_players *players, t_cell cells[MAP_LEN][MAP_LEN])
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (cells[inc.i][inc.j].team_id > 0)
			{
				players[inc.k].pid = cells[inc.i][inc.j].pid;
				inc.k++;
			}
			inc.j++;
		}
		inc.i++;
	}
}

uint32_t	players_getnb(t_cell cells[MAP_LEN][MAP_LEN])
{
	t_inc			inc;
	uint32_t		players_nb;

	ft_memset(&inc, 0, sizeof inc);
	players_nb = 0;
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (cells[inc.i][inc.j].team_id > 0)
				players_nb++;
			inc.j++;
		}
		inc.i++;
	}
	return (players_nb);
}

void    players_move(t_gamedata *gdata, void *map_mem,
			t_cell cells[MAP_LEN][MAP_LEN])
{
	size_t 	i = 0;
	// send msg when every players have played
	// forget sending message to team leader
	while (i < players_getnb(cells)) {
		gdata->msgbuf.mtype = (long)INT_MAX + gdata->players[i].pid;
		if (msgsnd(gdata->msgq_id, &gdata->msgbuf, sizeof gdata->msgbuf.mtext, 0) == -1)
			perr_exit("players_move msgsnd");
		sleep(1);
		i++;
	}
	printf("sendmsg to %d players\n", players_getnb(cells));
	// waiting every players to have played
	if (msgrcv(gdata->msgq_id, &gdata->msgbuf, sizeof gdata->msgbuf.mtext,
				gdata->msgbuf.mtype, 0) == -1)
		perr_exit("players_move msgrcv");
	map_fill(map_mem, cells);
	map_print(cells, 0);
}

void    game_init(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN])
{
	char            enter[8];
	t_gamedata		gdata;

	// list of all players to know which player to play
	ft_memset(&gdata.msgbuf, 0, sizeof gdata.msgbuf);
	read(0, enter, sizeof enter);
	if (enter[0] == '\n') {
		gdata.players_nb = players_getnb(cells);
		if ((gdata.players = calloc(gdata.players_nb + 1, sizeof(t_players)))
				== NULL)
			perr_exit("game_init calloc");
		players_get(gdata.players, cells);
		if ((gdata.key = ftok("./src/msg.c", '*')) == -1)
			perr_exit("game_init ftok");
		if ((gdata.msgq_id = msgget(gdata.key, 0644)) == -1)
			perr_exit("game_init msgget");
		fcntl(0, F_SETFL, fcntl(0, F_GETFL) & ~(O_NONBLOCK));
		while (1)
		{
			printf("Press enter to play one turn\n");
			ft_memset(enter, 0, sizeof enter);
			fgets(enter, sizeof enter, stdin);
			if (enter[0] == '\n')
				players_move(&gdata, map_mem, cells);
			gdata.players_nb = players_getnb(cells);
			players_get(gdata.players, cells);
			// send msg on pid that need to be played (msg_id = MAX_INT + pid())
			// then tick player has been played
			// receive msg on same pid, it mean process has played (reprint map)
		}
	}
}

int     main()
{
	void    *map_mem;
	t_cell  cells[MAP_LEN][MAP_LEN];
	t_cell  cells_tmp[MAP_LEN][MAP_LEN];

	// remove struct players and add played in t_cells in shm instead
	// must be able to close and reopen graphic client and see the same map
	// step by step mode / no step by step mode
	// (pass throug player played msgq (INT_MAX + PID) smth
	// 		to indicate to not waiting on step by step msgq
	map_mem = NULL;
	ft_memset(cells, 0, MAP_SIZE);
	map_get(&map_mem);
	map_fill(map_mem, cells);
	map_print(cells, 1);
	fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);
	while (1)
	{
		ft_memcpy(cells_tmp, cells, MAP_SIZE);
		map_fill(map_mem, cells);
		if (ft_memcmp(cells_tmp, cells, MAP_SIZE) != 0)
			map_print(cells, 1);
		game_init(map_mem, cells);
		sleep(1);
	}
	return (0);
}
