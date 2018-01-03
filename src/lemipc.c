#include "lemipc.h"
t_data	g_data;

void	move_player(pid_t pid)
{
	t_msgbuf	msgbuf;
	pid_t		ennemy_pid;
	t_cell		*current_cell;

	map_currentcell(pid, &current_cell);
	if (teamleader_exist() == 0)
	 	(*current_cell).team_leader = 1;
	if ((*current_cell).team_leader == 1)
	{
		/* func to determine ennemy_pid */
		// set ennemy_pid once at beggining and when target change
		/* (*current_cell).ennemy_pid = ennemy_pid; */
		// send ennemy target to same team player
		send_target();
	}
	else {
		// need to receive once at beggining and when target change
		// (or it will block)
		if (msgrcv(g_data.msgq_id, &msgbuf, sizeof msgbuf.mtext,
				g_data.team_id, 0) == -1)
			perr_exit("communicate msgrcv");
		ennemy_pid = ft_atoi(msgbuf.mtext);
	}
	// func to move player depending to ennemy_pid
	// fill cells
	// update shmem
}

void	communicate()
{
	t_msgbuf	msgbuf;
	pid_t		pid;

	ft_memset(&msgbuf, 0, sizeof msgbuf);
	msgq_getid();
	pid = getpid();
	// msgtype = team id to send msg
	while (1)
	{
		if (msgrcv(g_data.msgq_id, &msgbuf, 0, pid, 0) == -1)
			perr_exit("communicate msgrcv");

		move_player(pid);
		msgbuf.mtype = pid;
		if (msgsnd(g_data.msgq_id, &msgbuf, 0, 0) == -1) // end of move (send to map_print bin)
			perr_exit("communicate msgsnd");
		// ! players has to played depending to their arrival in game and keep that order
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
