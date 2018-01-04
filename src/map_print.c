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
				players->pid = cells[inc.i][inc.j].pid;
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

void    player_move(t_gamedata *gdata, void *map_mem,
			t_cell cells[MAP_LEN][MAP_LEN])
{
	int		i;
	long	player_mtype;

	i = 0;
	while (gdata->players[i].pid != 0 && gdata->players[i].played == 1)
		i++;
	player_mtype = (long)INT_MAX + gdata->players[i].pid;
	gdata->msgbuf.mtype = player_mtype;
	if (msgsnd(gdata->msgq_id, &gdata->msgbuf, 0, 0) == -1)
		perr_exit("player_move msgsnd");
	printf("sendmsg to [%lu]\n", gdata->msgbuf.mtype);
	if (msgrcv(gdata->msgq_id, &gdata->msgbuf, 0, player_mtype, 0) == -1)
		perr_exit("player_move msgrcv");
	gdata->players[i].played = 1;
	map_fill(map_mem, cells);
	map_print(cells, 0);
}

void    game_init(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN])
{
	char            enter[8];
	t_gamedata		gdata;

	(void)map_mem;
	// list of all players to know which player to play
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
				player_move(&gdata, map_mem, cells);
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
