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

void	get_coords_err(int errtype, char usercoord[8], size_t usercoord_len)
{
	if (errtype == 1) {
		fprintf(stderr, "invalid coord (must be x, y)\n");
	}
	else if (errtype == 2) {
		fprintf(stderr, "invalid coord (must be within 0 - %u"
			" range\n", MAP_LEN);
	}
	ft_memset(usercoord, 0, usercoord_len);
}

void	get_coords(t_coord *coords)
{
	char		usercoord[8];
	char		**coords_str;

	ft_memset(usercoord, 0, sizeof usercoord);
	printf("Enter your coords (must be x, y) :\n");
	while (1)
	{
		fgets(usercoord, sizeof usercoord, stdin);
		coords_str = strsplit(usercoord, ',');
		if (sstrlen(coords_str) != 2) {
			get_coords_err(1, usercoord, sizeof usercoord);
			continue;
		}
		coords->x = atoi_max(coords_str[0]);
		coords->y = atoi_max(coords_str[1]);
		if (coords->x > (MAP_LEN - 1) || coords->y > (MAP_LEN - 1)) {
			get_coords_err(2, usercoord, sizeof usercoord);
			continue;
		}
		else
			break ;
	}
	sstrfree(coords_str);
}

void	map_addplayer(void *map_mem, t_cell cells[MAP_LEN][MAP_LEN])
{
	t_coord		coords;

	get_coords(&coords);
	cells[coords.x][coords.y].team_id = g_data.team_id;
	cells[coords.x][coords.y].pid = getpid();
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
