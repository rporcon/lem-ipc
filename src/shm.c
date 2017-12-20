#include "lemipc.h"
		
int		map_init(void **map_mem)
{
	int		fd;
	size_t	len;

	shm_unlink("/shm-lemipc_map"); //
	if ((fd = shm_open("/shm-lemipc_map", O_RDWR | O_CREAT | O_EXCL, 0666)) != -1)
	{
		len = sizeof(t_cell) * MAP_SIZE;
		if (ftruncate(fd, len) == -1)
			perr_exit("write ftruncate");
		if ((*map_mem = mmap(NULL, next_powerchr(len, getpagesize()), PROT_READ
				| PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED)
			perr_exit("write mmap");
		close(fd);
		return (1);
	}
	return (0);
}

void	map_addplayer(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN])
{
	// verif if team id not already exist
	// position player with some logic (for example no different team side by side)
	// need a team limit according to map size
	cells[0][0].team_id = g_opt.team_id;
	cells[0][0].pid = getpid();
	ft_memcpy(map_mem, cells, sizeof (t_cell) * MAP_SIZE);
}

void	map_print(t_cell cells[MAP_LEN][MAP_LEN])
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

void	map_read(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN])
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
	map_print(cells);
}

void	map_erase()
{
	int				fd;
	void			*mem;
	struct stat		st;

	if ((fd = shm_open("/shm-lemipc_map", O_RDONLY, 0666)) == -1)
		perr_exit("read shm_open");
	fstat(fd, &st);
	if ((mem = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0)
			) == MAP_FAILED)
		perr_exit("read mmap");
	close(fd);
	munmap(mem, st.st_size);
}
