#include "lemipc.h"

void	sighandler(int sig)
{
	t_cell			*current;
	struct stat		st;
	int				fd;

	current = NULL;
	if (sig == SIGINT)
	{
		map_fill();
		map_currentcell(&current);
		if (current != NULL)
			ft_memset(current, 0, sizeof *current);
		ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
		if ((fd = shm_open("/shm-lemipc_map", O_RDONLY, 0644)) == -1)
			perr_exit("ressources_erase shm_open");
		fstat(fd, &st);
		close(fd);
		munmap(g_data.map_mem, st.st_size);
		if (enemies_alive() == 0 && g_data.gameLaunched == 1)
			ressources_erase();
	}
	exit (0);
}

void	sighandle()
{
	struct sigaction	sigact;

	ft_memset(&sigact, 0, sizeof sigact);
	sigact.sa_handler = sighandler;
	sigaction(SIGINT, &sigact, NULL);
}
