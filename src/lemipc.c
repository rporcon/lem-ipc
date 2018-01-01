#include "lemipc.h"
t_data	g_data = {0};

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
	map_get(&map_mem);
	map_fill(map_mem, cells);
	map_addplayer(map_mem, cells);
	while (1);
	return (0);
}
