#include "print_map.h"

void    map_get(void **map_mem)
{
    int     fd;

	while (1)
	{
		if ((fd = shm_open("/shm-lemipc_map", O_RDONLY, 0644)) != -1)
			break ;
		sleep (1);
	}
    if ((*map_mem = mmap(NULL, next_powerchr(MAP_SIZE, getpagesize()), PROT_READ
                , MAP_SHARED, fd, 0)) == MAP_FAILED)
    	perr_exit("map_get mmap");
    close(fd);
}

void	map_fill(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN])
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			cells[inc.i][inc.j] = ((t_cell *)map_mem)[inc.k];
			inc.j++;
			inc.k++;
		}
		inc.i++;
	}
}

void	map_print(t_cell cells[MAP_LEN][MAP_LEN])
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof inc);
	ft_putstr("--------------------------------\n");
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (cells[inc.i][inc.j].team_id == 0)
				ft_putchar('o');
			else
				printf("%u", cells[inc.i][inc.j].team_id);
			fflush(stdout);
			ft_putstr("   ");
			inc.j++;
		}
		ft_putstr("\n\n");
		inc.i++;
	}
	ft_putstr("--------------------------------\n"
			"Press enter to launch the game\n");
}

void    game_init()
{
	char            enter[8];

	read(0, enter, sizeof enter);
	if (enter[0] == '\n') {
		printf("Press enter to play one turn\n");
		while (1)
		{
			ft_memset(enter, 0, sizeof enter);
			fgets(enter, sizeof enter, stdin);
			if (enter[0] == '\n')
				printf("one move");
			// one turn or one move each enter ??
		}
	}
}

int     main()
{
	void    *map_mem;
	t_cell  cells[MAP_LEN][MAP_LEN];
	t_cell  cells_tmp[MAP_LEN][MAP_LEN];

	map_mem = NULL;
	ft_memset(cells, 0, MAP_SIZE);
	map_get(&map_mem);
	map_fill(map_mem, cells);
	map_print(cells);
	fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);
	while (1)
	{
		ft_memcpy(cells_tmp, cells, MAP_SIZE);
		map_fill(map_mem, cells);
		if (ft_memcmp(cells_tmp, cells, MAP_SIZE) != 0)
			map_print(cells);
		game_init();
		sleep(1);
	}
	return (0);
}
