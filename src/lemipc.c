#include "lemipc.h"
t_data	g_data;

void	move_player(pid_t pid)
{
	t_msgbuf	msgbuf;
	t_cell		*current_cell;

	map_currentcell(pid, &current_cell);
	if (teamleader_exist() == 0) {
		printf("pid: %d is team leader\n", (*current_cell).pid);
	 	(*current_cell).team_leader = 1;
	}
	if ((*current_cell).ennemy_set == 0 && (*current_cell).team_leader == 1)
	{
		printf("communicate begin\n");
		if (msgrcv(g_data.msgq_id, &msgbuf, sizeof msgbuf.mtext,
				(long)INT_MAX + pid, 0) == -1)
			perr_exit("communicate msgrcv");
		/* func to determine ennemy_pid */
		// set ennemy_pid once at beggining and when target change
		/* (*current_cell).ennemy_pid = ennemy_pid; */
		(*current_cell).ennemy_set = 1;
		printf("team leader\n");
		// send ennemy target to same team player
		send_target();
	}
	else if ((*current_cell).ennemy_set == 0)
	{
		printf("non team leader\n");
		if (msgrcv(g_data.msgq_id, &msgbuf, sizeof msgbuf.mtext,
				g_data.team_id, 0) == -1)
			perr_exit("communicate msgrcv");
		(*current_cell).ennemy = ft_atoi(msgbuf.mtext);
		printf("received ennemy: %d\n", (*current_cell).ennemy);
		(*current_cell).ennemy_set = 1;
	}
	// func to move player depending to ennemy_pid
	// test
	g_data.cells[2][2].team_id = 42;
	//
	ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
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
		printf("communicate waiting msg [%lu], pid: {%u}\n", (long)INT_MAX + pid, pid);
		sleep(1);
		map_fill();
		move_player(pid);
		msgbuf.mtype = (long)INT_MAX + pid;
		// send when every players has played
		if (msgsnd(g_data.msgq_id, &msgbuf, sizeof msgbuf.mtext, 0) == -1) // end of move (send to map_print bin)
			perr_exit("communicate msgsnd");
		printf("communicate end\n");
		// ! players has to played depending to their arrival in game
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
