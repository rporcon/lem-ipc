#include "lemipc.h"

t_opt	g_opt = {0};

int		write_shm(t_cell cells[MAP_LEN][MAP_LEN])
{
	int		fd;
	size_t	len;
	void	*mem;

	shm_unlink("/shm-lemipc_map"); //
	if ((fd = shm_open("/shm-lemipc_map", O_RDWR | O_CREAT | O_EXCL, 0666)) != -1)
		perr_exit("write shm_open");
	{
		len = sizeof(t_cell) * MAP_SIZE;
		if (ftruncate(fd, len) == -1)
			perr_exit("write ftruncate");
		if ((mem = mmap(NULL, next_powerchr(len, getpagesize()), PROT_READ
				| PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED)
			perr_exit("write mmap");
		close(fd);
		ft_memcpy(mem, cells, sizeof (t_cell) * MAP_SIZE);
		return (1);
	}
	return (0);
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

int		main(int ac, char **av)
{
	t_cell cells[MAP_LEN][MAP_LEN];

	get_args(ac, av);
	ft_memset(cells, 0, sizeof (t_cell) * MAP_SIZE);
	if (write_shm(cells) == 1)
	{
		read_shm();
		while (1);
	}
	return (0);
}
