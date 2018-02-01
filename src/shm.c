#include "lemipc.h"

void	map_init()
{
	int		fd;
	key_t	key;

	if ((fd = shm_open("/shm-lemipc_map", O_RDWR | O_CREAT | O_EXCL, 0644))
			!= -1)
	{
		if (ftruncate(fd, MAP_SIZE) == -1)
			perr_exit("map_init ftruncate");
		if (mmap(NULL, next_powerchr(MAP_SIZE, getpagesize()),
				PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0) == MAP_FAILED)
			perr_exit("map_init mmap");
		close(fd);
		if (sem_open("/sem-lemipc_map", O_CREAT, 0644, 1) == SEM_FAILED)
			perr_exit("map_init sem_open");
		if ((key = ftok("./src/msg.c", '*')) == -1)
			perr_exit("map_init ftok");
		if (msgget(key, 0644 | IPC_CREAT) == -1)
			perr_exit("map_init msgget");
	}
}

int		print_cells()
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			printf("[%lld][%lld] pid: %u, team_leader: %d, value: %llu\n",
				inc.i, inc.j, g_data.cells[inc.i][inc.j].pid,
				g_data.cells[inc.i][inc.j].team_leader,
				g_data.cells[inc.i][inc.j].val);
			inc.j++;
			inc.k++;
		}
		inc.i++;
	}
	return (0);
}

void	map_get()
{
	int		fd;

	if ((fd = shm_open("/shm-lemipc_map", O_RDWR, 0644)) == -1)
		perr_exit("map_get shm_open");
	if ((g_data.map_mem = mmap(NULL, next_powerchr(MAP_SIZE, getpagesize()),
			PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED)
		perr_exit("map_get mmap");
	close(fd);
}

void	get_coords_err(int errtype, char usercoord[8], size_t usercoord_len)
{
	if (errtype == 1) {
		fprintf(stderr, "invalid coord (must be y, x)\n");
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
	printf("Enter your coords (must be y, x) :\n");
	while (1)
	{
		fgets(usercoord, sizeof usercoord, stdin);
		coords_str = strsplit(usercoord, ',');
		if (sstrlen(coords_str) != 2) {
			get_coords_err(1, usercoord, sizeof usercoord);
			continue;
		}
		coords->y = atoi_max(coords_str[0]);
		coords->x = atoi_max(coords_str[1]);
		if (coords->x > (MAP_LEN - 1) || coords->y > (MAP_LEN - 1)) {
			get_coords_err(2, usercoord, sizeof usercoord);
			continue;
		}
		else
			break ;
	}
	sstrfree(coords_str);
}

void	map_addplayer()
{
	t_coord		coords;

    if ((g_data.sem = sem_open("/sem-lemipc_map", 0)) == SEM_FAILED)
        perr_exit("map_addplayer sem_open");
	get_coords(&coords);
	if (g_data.cells[coords.y][coords.x].team_id > 0)
		err_exit("player already exist on this coord", 1);
    if (sem_wait(g_data.sem) == -1)
        perr_exit("map_addplayer sem_wait");
	g_data.cells[coords.y][coords.x].team_id = g_data.team_id;
	g_data.cells[coords.y][coords.x].pid = getpid();
	g_data.cells[coords.y][coords.x].x = coords.x;
	g_data.cells[coords.y][coords.x].y = coords.y;
	ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
    if (sem_post(g_data.sem) == -1)
        perr_exit("map_addplayer sem_post");
}

void	map_currentcell(t_cell **current_cell)
{
	t_inc		inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.pid == g_data.cells[inc.i][inc.j].pid)
			{
				*current_cell = &g_data.cells[inc.i][inc.j];
				return ;
			}
			inc.j++;
			inc.k++;
		}
		inc.i++;
	}
}

void	map_fill()
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			g_data.cells[inc.i][inc.j] = ((t_cell *)g_data.map_mem)[inc.k];
			g_data.cells[inc.i][inc.j].y = inc.i;
			g_data.cells[inc.i][inc.j].x = inc.j;
			inc.j++;
			inc.k++;
		}
		inc.i++;
	}
}

void	ressources_erase()
{
	int				fd;
	struct stat		st;
	sem_t			*sem;
	int 			msgq_id;
	key_t			key;

	if ((fd = shm_open("/shm-lemipc_map", O_RDONLY, 0644)) == -1)
		perr_exit("ressources_erase shm_open");
	fstat(fd, &st);
	close(fd);
	munmap(g_data.map_mem, st.st_size);
	shm_unlink("/shm-lemipc_map");
    if ((sem = sem_open("/sem-lemipc_map", 0)) == SEM_FAILED)
        perr_exit("ressources_erase sem_open");
    sem_unlink("/sem-lemipc_map");
	if ((key = ftok("./src/msg.c", '*')) == -1)
		perr_exit("ressources_erase ftok");
	if ((msgq_id = msgget(key, 0644 | IPC_CREAT)) == -1)
		perr_exit("ressources_erase msgget");
	msgctl(g_data.msgq_id, IPC_RMID, NULL);
	exit(0);
}
