#include "lemipc.h"
t_data	g_data;

int		print_cells()
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			printf("[%zu][%zu] pid: %u, team_leader: %d\n",
				inc.i, inc.j,
				g_data.cells[inc.i][inc.j].team_leader,
				g_data.cells[inc.i][inc.j].pid);
			inc.j++;
			inc.k++;
		}
		inc.i++;
	}
	return (0);
}

void	move_player(pid_t pid)
{
	t_msgbuf	msgbuf;
	t_cell		*current_cell;

	// semaphore
	map_currentcell(pid, &current_cell);
	if (teamleader_exist() == 0) {
	 	(*current_cell).team_leader = 1;
		printf("team leader\n");
		/* ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE); */
		//
		map_fill();
		print_cells();
		printf("print_cells\n");
		g_data.cells[0][0].played = 1;
		g_data.cells[0][0].pid = 4242;
		ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
		//
	}
	if ((*current_cell).ennemy_set == 0 && (*current_cell).team_leader == 1)
	{
		/* func to determine ennemy_pid */
		// set ennemy_pid once at beggining and when target change
		/* (*current_cell).ennemy_pid = ennemy_pid; */
		/* while (playersPlayedNb() == 0) { */
		/* 	ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE); */
			sleep(1);
		/* } */
		sleep(1);
		(*current_cell).ennemy_set = 1;
		printf("[team leader]  pid: {%d} send ennemy\n", pid);
		// send ennemy target to same team player
		send_target();
	}
	else if ((*current_cell).ennemy_set == 0)
	{
		printf("[non team leader], rcv on: [%lu], pid: {%u}\n", (long)INT_MAX + pid, pid);
		if (msgrcv(g_data.msgq_id, &msgbuf, sizeof msgbuf.mtext,
				g_data.team_id, 0) == -1)
			perr_exit("move_player msgrcv");
		(*current_cell).ennemy = ft_atoi(msgbuf.mtext);
		printf("received ennemy: %d\n", (*current_cell).ennemy);
		(*current_cell).ennemy_set = 1;
	}
	// test
	printf("set player\n");
	// clear old pos
	/* ft_memset(current_cell, 0, sizeof *current_cell); */
	// func to move player depending to ennemy_pid instead of below
	g_data.cells[4][5].team_id = 42;
	g_data.cells[4][5].played = 1;
	//
}

void	communicate()
{
	t_msgbuf	msgbuf;
	pid_t		pid;

	ft_memset(&msgbuf, 0, sizeof msgbuf);
	msgq_getid();
	pid = getpid();
	while (1)
	{
		sleep(1);
		map_fill();
		if (msgrcv(g_data.msgq_id, &msgbuf, sizeof msgbuf.mtext,
				(long)INT_MAX + pid, 0) == -1)
			perr_exit("communicate msgrcv");
		printf("my turn\n");
		move_player(pid);
		// if first player has played
		// send when every players has played
		if (playersPlayed() == 1) {
			msgbuf.mtype = INT_MAX;
			if (msgsnd(g_data.msgq_id, &msgbuf,
					sizeof msgbuf.mtext, 0) == -1) // all players played
				perr_exit("communicate msgsnd");
			printf("msgsnd end of turn");
			playersResetPlayed();
		}
		/* ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE); */
	}
}

int		main(int ac, char **av)
{
	// add an erase arg to call ressources_erase
	/* ressources_erase(); exit(0); */
	ft_memset(&g_data, 0, sizeof g_data);
	map_init();
	get_args(ac, av);
	sighandle(); // clear only if last process quit
				 // handle too much processus error case
	map_get();
	map_fill();
	map_addplayer();

	communicate();
	return (0);
}
