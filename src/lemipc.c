#include "lemipc.h"
t_data	g_data = {0};

int		main(int ac, char **av)
{
	void	*map_mem;
	t_cell	cells[MAP_LEN][MAP_LEN];
	t_cell	cells_tmp[MAP_LEN][MAP_LEN];

	map_mem = NULL;
	ft_memset(cells, 0, MAP_SIZE);
	get_args(ac, av);
	if (map_init(&map_mem) == 1)
	{
		sighandle();
		map_addplayer(map_mem, cells);
		map_read(map_mem, cells);
		map_print(cells);
		while (1)
		{
			ft_memcpy(cells_tmp, cells, MAP_SIZE);
			map_read(map_mem, cells);
			if (ft_memcmp(cells_tmp, cells, MAP_SIZE) != 0)
				map_print(cells);
			sleep(1);
		}
	}
	else {
		map_get(&map_mem);
		map_read(map_mem, cells);
		map_addplayer(map_mem, cells);
		while (1);
	}
	return (0);
}
