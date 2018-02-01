/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:38:57 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/01 17:13:18 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

t_data	g_data;

void	communicate(void)
{
	msgq_getid();
	/* printf("pid: %u\n", g_data.pid); */
	while (1)
	{
		if (msgrcv(g_data.msgq_id, &g_data.msgbuf, sizeof(g_data.msgbuf.mtext),
					(long)INT_MAX + g_data.pid, 0) == -1)
			perr_exit("communicate msgrcv");
		if (g_data.gameLaunched == 0)
			g_data.gameLaunched = 1;
		map_fill();
		if (sem_wait(g_data.sem) == -1)
			perr_exit("communicate sem_wait");
		move_player();
		if (sem_post(g_data.sem) == -1)
			perr_exit("communicate sem_post");
		if (playersPlayed() == 1)
		{
			g_data.msgbuf.mtype = INT_MAX;
			if (msgsnd(g_data.msgq_id, &g_data.msgbuf,
						sizeof(g_data.msgbuf.mtext), 0) == -1)
				perr_exit("communicate msgsnd");
			playersResetPlayed();
			ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
		}
	}
}

int		main(int ac, char **av)
{
	// clear map
	ft_memset(&g_data, 0, sizeof(g_data));
	g_data.pid = getpid();
	map_init();
	get_args(ac, av);
	sighandle();
	map_get();
	map_fill();
	// error if player on case already exist
	map_addplayer();
	communicate();
	return (0);
}
