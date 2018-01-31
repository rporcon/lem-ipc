#include "lemipc.h"

void	sighandler(int sig)
{
	t_cell	*current;

	if (sig == SIGINT) {
		map_currentcell(&current);
		ft_memset(current, 0, sizeof *current);
		ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
		if (enemiesAlive() == 0)
			ressources_erase();
	}
}

void	sighandle()
{
	struct sigaction	sigact;

	ft_memset(&sigact, 0, sizeof sigact);
	sigact.sa_handler = sighandler;
	sigaction(SIGINT, &sigact, NULL);
}
