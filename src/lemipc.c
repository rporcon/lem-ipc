#include "lemipc.h"
t_data	g_data;


void	communicate()
{
	t_msgbuf	msgbuf;

	ft_memset(&msgbuf, 0, sizeof msgbuf);
	msgq_getid();
	printf("pid: %u\n", g_data.pid);
	while (1)
	{
		if (msgrcv(g_data.msgq_id, &msgbuf, sizeof msgbuf.mtext,
				(long)INT_MAX + g_data.pid, 0) == -1)
			perr_exit("communicate msgrcv");
		map_fill();
		if (sem_wait(g_data.sem) == -1)
			perr_exit("communicate sem_wait");
		move_player();
		if (sem_post(g_data.sem) == -1)
			perr_exit("communicate sem_post");
		if (playersPlayed() == 1) {
			msgbuf.mtype = INT_MAX;
			if (msgsnd(g_data.msgq_id, &msgbuf, sizeof msgbuf.mtext, 0) == -1) // all players played
				perr_exit("communicate msgsnd");
			printf("msgsnd end of turn\n");
			playersResetPlayed();
			ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE); // semaphore ?
		}
	}
}

int		main(int ac, char **av)
{
	// add an erase arg to call ressources_erase
	/* ressources_erase(); exit(0); */
	ft_memset(&g_data, 0, sizeof g_data);
	g_data.pid = getpid();
	map_init();
	get_args(ac, av);
	sighandle(); // clear only if last process quit
				 // handle too much processus error case
	map_get();
	map_fill();
	// error if player on case already exist
	map_addplayer();

	communicate();
	return (0);
}
