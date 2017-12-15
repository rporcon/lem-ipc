#include "lemipc.h"

void	init_map(t_cell cells[MAP_LEN][MAP_LEN])
{
	size_t		i;

	i = 0;
	ft_memset(cells, 0, MAP_SIZE);
	while (i < MAP_SIZE)
	{
		ft_memset(cells[i], 0, MAP_SIZE);
		i++;
	}
}

void	init_shm(t_cell cells[MAP_LEN][MAP_LEN])
{
	int		fd;
	size_t	len;
	void	*mem;

	len = sizeof(t_cell) * MAP_SIZE;
	fd = shm_open("/shm-lemipc_map", O_RDWR, 0666);
	ftruncate(fd, len);
	mem = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);
	ft_memcpy(mem, cells, MAP_SIZE); // not ok(contiguous addr)
}

int		main(void)
{
	t_cell cells[MAP_LEN][MAP_LEN];

	init_map(cells);
	init_shm(cells);
	return (0);
}
