/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:04:36 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/05 08:45:54 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	munmap_map(void)
{
	int				fd;
	struct stat		st;

	if ((fd = shm_open("/shm-lemipc_map", O_RDWR, 0644)) == -1 && DBG == 1)
		perr_exit("munmap_map shm_open");
	else
		return ;
	fstat(fd, &st);
	close(fd);
	munmap(g_data.map_mem, st.st_size);
}

void	sighandler(int sig)
{
	t_cell			*current;

	current = NULL;
	if (sig == SIGINT)
	{
		map_fill();
		map_currentcell(&current);
		if (current != NULL)
			ft_memset(current, 0, sizeof(*current));
		ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
		munmap_map();
		if (enemies_alive() == 0 && g_data.game_launched == 1)
			ressources_erase();
	}
	exit(0);
}

void	sighandle(void)
{
	struct sigaction	sigact;

	ft_memset(&sigact, 0, sizeof(sigact));
	sigact.sa_handler = sighandler;
	sigaction(SIGINT, &sigact, NULL);
}
