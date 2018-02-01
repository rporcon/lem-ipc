#include "lemipc.h"

void	sighandler(int sig)
{
	t_cell	*current;

	if (sig == SIGINT) {
		if (g_data.gameLaunched == 1)
		{
			map_fill();
			map_currentcell(&current);
			if (enemiesAlive() == 0 && g_data.gameLaunched == 1)
			{
				ft_memset(current, 0, sizeof *current);
				ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
				ressources_erase();
			}
			else {
				ft_memset(current, 0, sizeof *current);
				ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
			}
		}
		else
			ressources_erase();
		exit (0);
	}
}

void	sighandle()
{
	struct sigaction	sigact;

	ft_memset(&sigact, 0, sizeof sigact);
	sigact.sa_handler = sighandler;
	sigaction(SIGINT, &sigact, NULL);
}
