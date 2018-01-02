#include "lemipc.h"
t_data	g_data = {0};

void	communicate()
{
	int			msgq_id;
	t_msgbuf	msgbuf;

	ft_memset(&msgbuf, 0, sizeof msgbuf);
	msgq_getid(&msgq_id);
	// msgtype = pid to send msg
	while (1)
	{
		if (msgrcv(msgq_id, &msgbuf, sizeof msgbuf.mtext, 0, 0) == -1)
			perr_exit("communicate msgrcv");
		printf("message received on queue");
		// supposition
		// create another shared memory segment for data
		// ! players has to played depending to their arrival in game and keep
		// that order
		// send msg to each same team id (they have to focus same ennemy)
		// when msg receive -> tick player status to "has played"
		// ??? if not good player receive msg -> resend  ??? 
		// resend msg to an other member of same team if available
		// struct to know current status of each player (has played ?)
		// -> check if all players team has played then tick team has played = ok
		// when all team has played -> wait enter of map_print to play next turn
	}

}

int		main(int ac, char **av)
{
	void	*map_mem;
	t_cell	cells[MAP_LEN][MAP_LEN];

	/* map_erase(); exit(0); */
	map_init();
	map_mem = NULL;
	ft_memset(cells, 0, MAP_SIZE);
	get_args(ac, av);
	sighandle(); // clear only if last process quit
				 // handle too much processus error case
	map_get(&map_mem);
	map_fill(map_mem, cells);
	map_addplayer(map_mem, cells);

	communicate();
	return (0);
}
