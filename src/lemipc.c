#include "lemipc.h"

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

void	fill_cells(void *mem, t_cell cells[MAP_LEN][MAP_LEN])
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

void	print_map(t_cell cells[MAP_LEN][MAP_LEN])
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (cells[inc.i][inc.j].team_id == 0)
				ft_putchar('o');
			else
				printf("%zu", cells[inc.i][inc.j].team_id);
			fflush(stdout);
			ft_putstr("   ");
			inc.j++;
		}
		ft_putstr("\n\n");
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
	fill_cells(mem, cells);
	munmap(mem, st.st_size);
	print_map(cells);
}

int		main(void)
{
	t_cell cells[MAP_LEN][MAP_LEN];

	ft_memset(cells, 0, sizeof (t_cell) * MAP_SIZE);
	write_shm(cells);
	read_shm();
	return (0);
}
