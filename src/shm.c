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

int		teamleader_exist()
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].team_id == g_data.team_id
					&& g_data.cells[inc.i][inc.j].team_leader == 1)
				return (1);
			inc.j++;
			inc.k++;
		}
		inc.i++;
	}
	return (0);
}

void	map_addplayer()
{
	t_coord		coords;

    if ((g_data.sem = sem_open("/sem-lemipc_map", 0)) == SEM_FAILED)
        perr_exit("map_addplayer sem_open");
    if (sem_wait(g_data.sem) == -1)
        perr_exit("map_addplayer sem_wait");
	get_coords(&coords);
	/* if (teamleader_exist() == 0) */
	/* 	g_data.cells[coords.x][coords.y].team_leader = 1; */
	// determine team_leader before launching game
	g_data.cells[coords.x][coords.y].team_id = g_data.team_id;
	g_data.cells[coords.x][coords.y].pid = getpid();
	ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
    if (sem_post(g_data.sem) == -1)
        perr_exit("map_addplayer sem_post");
}

void	map_currentcell(pid_t pid, t_cell **current_cell)
{
	t_inc		inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (pid == g_data.cells[inc.i][inc.j].pid)
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

	if ((fd = shm_open("/shm-lemipc_map", O_RDONLY, 0644)) == -1)
		perr_exit("read shm_open");
	fstat(fd, &st);
	close(fd);
	munmap(g_data.map_mem, st.st_size);
	shm_unlink("/shm-lemipc_map");
    sem_unlink("/sem-lemipc_map");
	msgctl(g_data.msgq_id, IPC_RMID, NULL);
	exit(0);
}
