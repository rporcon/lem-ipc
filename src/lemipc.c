#include "lemipc.h"
t_data	g_data = {0};

void	communicate()
{
	int			msgq_id;
	t_msgbuf	msgbuf;

	ft_memset(&msgbuf, 0, sizeof msgbuf);
	msgq_getid(&msgq_id);
	// msgtype = team id to send msg
	while (1)
	{
		/* if (msgrcv(msgq_id, &msgbuf, sizeof msgbuf.mtext, 0, 0) == -1) */
		/* 	perr_exit("communicate msgrcv"); */
		/* printf("message received on queue"); */
		// supposition
		// receive msg on process pid
		// send msg on same pid when played
		// ! players has to played depending to their arrival in game and keep that order
	}
}

int		main(int ac, char **av)
{
	void	*map_mem;
	t_cell	cells[MAP_LEN][MAP_LEN];

	// add an erase arg to call ressources_erase
	/* ressources_erase(); exit(0); */
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
