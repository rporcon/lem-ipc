#include "lemipc.h"

void	sighandler(int sig)
{
	if (sig == SIGINT)
	{
		shm_erase();
	}
}

void	sighandle()
{
	struct sigaction	sigact;

	ft_memset(&sigact, 0, sizeof sigact);
	sigact.sa_handler = sighandler;
	sigaction(SIGINT, &sigact, NULL);
}
