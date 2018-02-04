/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm_mapinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 19:02:37 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/03 19:02:40 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	map_init(void)
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
		if (sem_open("/sem-lemipc_map", O_CREAT, S_IRUSR | S_IWUSR, 1) == SEM_FAILED)
			perr_exit("map_init sem_open");
		if ((key = ftok("./src/msg.c", '*')) == -1)
			perr_exit("map_init ftok");
		if (msgget(key, 0644 | IPC_CREAT) == -1)
			perr_exit("map_init msgget");
	}
}

int		print_cells(void)
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof(inc));
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

void	map_get(void)
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
	if (errtype == 1)
	{
		fprintf(stderr, "invalid coord (must be y, x)\n");
	}
	else if (errtype == 2)
	{
		fprintf(stderr, "invalid coord (must be within 0 - %u"
				" range\n", MAP_LEN);
	}
	ft_memset(usercoord, 0, usercoord_len);
}

void	get_coords(t_coord *coords)
{
	char		usercoord[8];
	char		**coords_str;

	ft_memset(usercoord, 0, sizeof(usercoord));
	while (1)
	{
		if (fgets(usercoord, sizeof(usercoord), stdin) == NULL)
			err_exit("invalid coord", 1);
		coords_str = strsplit(usercoord, ',');
		if (sstrlen(coords_str) != 2)
		{
			get_coords_err(1, usercoord, sizeof(usercoord));
			continue;
		}
		coords->y = atoi_max(coords_str[0]);
		coords->x = atoi_max(coords_str[1]);
		if (coords->x > (MAP_LEN - 1) || coords->y > (MAP_LEN - 1))
		{
			get_coords_err(2, usercoord, sizeof(usercoord));
			continue;
		}
		else
			break ;
	}
	sstrfree(coords_str);
}
