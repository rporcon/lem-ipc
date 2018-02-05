/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:38:57 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/05 18:13:51 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

t_data	g_data;

void	end_of_turn(void)
{
	g_data.msgbuf.mtype = INT_MAX;
	if (msgsnd(g_data.msgq_id, &g_data.msgbuf,
			sizeof(g_data.msgbuf.mtext), 0) == -1)
		DBG == 1 ? perr_exit("communicate msgsnd") : exit(0);
	players_reset_played();
	ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
}

void	communicate(void)
{
	msgq_getid();
	while (1)
	{
		if (msgrcv(g_data.msgq_id, &g_data.msgbuf, sizeof(g_data.msgbuf.mtext),
				(long)INT_MAX + g_data.pid, 0) == -1)
			DBG == 1 ? perr_exit("communicate msgrcv") : exit(0);
		if (sem_wait(g_data.sem) == -1)
			perr_exit("communicate sem_wait");
		map_fill();
		move_player();
		if (DBG == 1)
			printf("players_played_nb: %d, players_nb: %d\n",
				players_played_nb(), players_nb());
		if (players_played() == 1)
			end_of_turn();
		if (sem_post(g_data.sem) == -1)
			perr_exit("communicate sem_post");
		if (DBG == 1)
			printf("turn %d finished\n", ++g_data.dbg_i);
	}
}

int		main(int ac, char **av)
{
	ft_memset(&g_data, 0, sizeof(g_data));
	g_data.pid = getpid();
	if (DBG == 1)
		printf("pid: [%u]\n", g_data.pid);
	get_args(ac, av);
	map_init();
	sighandle();
	map_get();
	map_fill();
	map_addplayer();
	communicate();
	return (0);
}
