#include "lemipc.h"

t_data	g_data = {0};


int		main(int ac, char **av)
{
	void	*map_mem;
	t_cell	cells[MAP_LEN][MAP_LEN];

	ft_memset(cells, 0, sizeof (t_cell) * MAP_SIZE);
	get_args(ac, av);
	if (map_init(&map_mem) == 1)
	{
		map_addplayer(map_mem, cells);
		map_read(map_mem, cells);
		while (1);
	}
	else {
		while (1);
	}
	return (0);
}
