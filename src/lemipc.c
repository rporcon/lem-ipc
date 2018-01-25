#include "lemipc.h"
t_data	g_data;

uint32_t	enemy_chr(t_cell current_cell)
{
	t_inc			inc;
	uint32_t 		enemy_pid;

	/* inc.i = current_cell.x; */
	/* inc.j = current_cell.y; */
	enemy_pid = 0;
	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].team_id != current_cell.team_id
					&& g_data.cells[inc.i][inc.j].val == 0)
			{
				// end condition (return coord of enemy)
				// or make a func to return coord of pid
				if (g_data.cells[inc.i][inc.j].team_id > 0)
					return (g_data.cells[inc.i][inc.j].pid);
				g_data.cells[inc.i][inc.j].val = abs((int)(current_cell.x -
					g_data.cells[inc.i][inc.j].x)) + abs((int)(current_cell.y -
					g_data.cells[inc.i][inc.j].y));
			}
			inc.j++;
		}
		inc.i++;
	}
	return (enemy_pid);
}

void	move_player(pid_t pid)
{
	t_msgbuf	msgbuf;
	t_cell		*current_cell;

	// semaphore
	map_currentcell(pid, &current_cell);
	if (teamleader_exist() == 0) {
	 	(*current_cell).team_leader = 1;
		ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
		//
		enemy_chr(*current_cell);
		print_cells();
		raise(SIGINT);
		//
	}
	if ((*current_cell).ennemy_set == 0 && (*current_cell).team_leader == 1)
	{
		/* func to determine ennemy_pid */
		// set ennemy_pid once at beggining and when target change
		/* (*current_cell).ennemy_pid = ennemy_pid; */
		while (playersPlayedNb() == 0) {
			ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
			sleep(1);
		}
		(*current_cell).ennemy_set = 1;
		printf("[team leader %d]  pid: {%d} send ennemy\n",
			g_data.team_id, pid);
		// send ennemy target to same team player
		send_target();
	}
	else if ((*current_cell).ennemy_set == 0)
	{
		printf("[non team leader], rcv on: [%lu], pid: {%u}\n", (long)INT_MAX + pid, pid);
		if (msgrcv(g_data.msgq_id, &msgbuf, sizeof msgbuf.mtext,
				g_data.team_id, 0) == -1)
			perr_exit("move_player msgrcv");
		(*current_cell).enemy_pid = ft_atoi(msgbuf.mtext);
		printf("received ennemy: %d\n", (*current_cell).enemy_pid);
		(*current_cell).ennemy_set = 1;
	}
	// test
	printf("set player\n");
	// clear old pos
	/* ft_memset(current_cell, 0, sizeof *current_cell); */
	// func to move player depending to ennemy_pid instead of below
	g_data.cells[4][5].team_id = 42;
	g_data.cells[4][5].played = 1;
	ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
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
		if (msgrcv(g_data.msgq_id, &msgbuf, sizeof msgbuf.mtext,
				(long)INT_MAX + pid, 0) == -1)
			perr_exit("communicate msgrcv");
		map_fill();
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
