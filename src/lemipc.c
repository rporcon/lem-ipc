#include "lemipc.h"

void	init_map(t_cell cells[MAP_LEN][MAP_LEN])
{
	size_t		i;

	i = 0;
	ft_memset(cells, 0, MAP_LEN);
	while (i < MAP_LEN)
	{
		ft_memset(cells[i], 0, MAP_LEN);
		i++;
	}
}

void	write_shm(t_cell cells[MAP_LEN][MAP_LEN])
{
	int		fd;
	size_t	len;
	void	*mem;

	len = sizeof(t_cell) * MAP_SIZE;
	shm_unlink("/shm-lemipc_map"); //
	if ((fd = shm_open("/shm-lemipc_map", O_RDWR | O_CREAT, 0666)) == -1)
		perr_exit("write shm_open");;
	if (ftruncate(fd, len) == -1)
		perr_exit("write ftruncate");
	if ((mem = mmap(NULL, next_powerchr(len, getpagesize()), PROT_READ
			| PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED)
		perr_exit("write mmap");
	close(fd);

	ft_memcpy(mem, cells, sizeof (t_cell) * MAP_SIZE);
}

void	update_cells(void *mem, t_cell cells[MAP_LEN][MAP_LEN])
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			cells[inc.i][inc.j] = ((t_cell *)mem)[inc.k];
			inc.j++;
			inc.k++;
		}
		inc.i++;
	}
}

void	read_shm()
{
	int				fd;
	void			*mem;
	t_cell			cells[MAP_LEN][MAP_LEN];
	struct stat		st;

	if ((fd = shm_open("/shm-lemipc_map", O_RDONLY, 0666)) == -1)
		perror("read shm_open");
	fstat(fd, &st);
	if ((mem = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0)
			) == MAP_FAILED)
		perr_exit("read mmap");
	close(fd);
	update_cells(mem, cells);
	munmap(mem, st.st_size);
}

int		main(void)
{
	t_cell cells[MAP_LEN][MAP_LEN];

	init_map(cells);
	write_shm(cells);
	read_shm();
	return (0);
}
