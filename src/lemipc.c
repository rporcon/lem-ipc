#include "lemipc.h"
t_data	g_data;

void 	resetCellsVal()
{
	t_inc 			inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			g_data.cells[inc.i][inc.j].val = 0;
			inc.j++;
		}
		inc.i++;
	}
}

void 	fill_enemies(t_cell enemies[ENEMY_SIZE], t_cell current,
			uint32_t *enemy_nb, t_inc inc)
{
	resetCellsVal();
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].team_id != current.team_id
					&& g_data.cells[inc.i][inc.j].val == 0)
			{
				if (g_data.cells[inc.i][inc.j].team_id > 0)
				{
					enemies[inc.k] = g_data.cells[inc.i][inc.j];
					inc.k++;
				}
				g_data.cells[inc.i][inc.j].val = abs((int)(current.x -
					g_data.cells[inc.i][inc.j].x)) + abs((int)(current.y -
					g_data.cells[inc.i][inc.j].y));
			}
			inc.j++;
		}
		inc.i++;
	}
	*enemy_nb = inc.k;
}

t_cell	*enemy_chr(t_cell current)
{
	t_cell			enemies[ENEMY_SIZE];
	t_cell			*enemy;
	uint32_t		enemy_nb;
	t_inc 			inc;

	ft_memset(&enemies, 0, sizeof enemies);
	ft_memset(&inc, 0, sizeof inc);
	enemy = malloc(sizeof *enemy);
	fill_enemies(enemies, current, &enemy_nb, inc);
	assert(enemy_nb > 0); //
	ft_memcpy(enemy, &enemies[0], sizeof *enemy);;
	inc.i = 1;
	while (inc.i < enemy_nb)
	{
		if (enemies[inc.i].val > enemy->val)
			ft_memcpy(enemy, &enemies[inc.i], sizeof *enemy);
		inc.i++;
	}
	printf("common enemy is: %d\n", enemy->pid);
	return (enemy);
}

t_cell 	nearestPosToEnemy(t_cell current)
{
	t_cell 		newPos;
	t_cell 		tmp;

	ft_memcpy(&newPos, &g_data.cells[current.x][current.y], sizeof newPos);
	newPos.val = UINT64_MAX;
	tmp = g_data.cells[current.x + 1][current.y];
	// made a func set newPos / val
	if (current.x + 1 < MAP_LEN && tmp.val != 0 && newPos.val > tmp.val)
	{
		newPos.val = tmp.val;
		newPos.x = current.x + 1;
	}
	tmp = g_data.cells[current.x - 1][current.y];
	if (current.x - 1 >= 0 && tmp.val != 0 && newPos.val > tmp.val)
	{
		newPos.val = tmp.val;
		newPos.x = current.x - 1;
	}
	tmp = g_data.cells[current.x][current.y + 1];
	if (current.y + 1 < MAP_LEN && tmp.val != 0 && newPos.val > tmp.val)
	{
		newPos.val = tmp.val;
		newPos.x = current.x;
		newPos.y = current.y + 1;
	}
	tmp = g_data.cells[current.x][current.y - 1];
	if (current.y - 1 >= 0 && tmp.val != 0 && newPos.val > tmp.val)
	{
		newPos.val = tmp.val;
		newPos.x = current.x;
		newPos.y = current.y - 1;
	}
	return (newPos);
}

t_cell 	moveToEnemy(t_cell current)
{
	t_inc 			inc;

	ft_memset(&inc, 0, sizeof inc);
	resetCellsVal();
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].team_id == 0
					&& g_data.cells[inc.i][inc.j].val == 0)
			{
				/* printf("[%lld]\n", current.enemy->x); */
				g_data.cells[inc.i][inc.j].val = abs((int)(current.enemy->x -
					g_data.cells[inc.i][inc.j].x)) + abs((int)(
					current.enemy->y - g_data.cells[inc.i][inc.j].y));
			}
			inc.j++;
		}
		inc.i++;
	}
	print_cells();
	return (nearestPosToEnemy(current));
}

void	move_player(pid_t pid)
{
	t_msgbuf	msgbuf;
	t_cell		*current;
	t_cell 		newPos;

	map_currentcell(pid, &current);
	if (teamleader_exist() == 0) {
	 	(*current).team_leader = 1;
		ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
	}
	if ((*current).ennemy_set == 0 && (*current).team_leader == 1)
	{
		while (playersPlayedNb() == 0) {
			ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
			sleep(1);
		}
		(*current).enemy = enemy_chr(*current);
		(*current).ennemy_set = 1;
		printf("[team leader] send ennemy[%lld][%lld]\n",
			(*current).enemy->x, (*current).enemy->y);
		// send ennemy target to same team player
		send_target((*current).enemy);
	}
	else if ((*current).ennemy_set == 0)
	{
		printf("[non team leader], rcv on: [%lu], pid: {%u}\n", (long)INT_MAX + pid, pid);
		if (msgrcv(g_data.msgq_id, &msgbuf, sizeof msgbuf.mtext,
				g_data.team_id, 0) == -1)
			perr_exit("move_player msgrcv");
		(*current).enemy = malloc(sizeof (t_cell));
		ft_memcpy((*current).enemy, (void *)msgbuf.mtext, sizeof (t_cell));
		printf("received ennemy: %d\n", (*current).enemy->pid);
		(*current).ennemy_set = 1;
	}
	// if newPos.val == 1 current is next to enemy
	// when enemy is cleared -> enemy_set = 0
	newPos = moveToEnemy(*current);
	printf("newPos: [%lld][%lld]\n", newPos.x, newPos.y);
	g_data.cells[newPos.x][newPos.y] = newPos;
	ft_memset(current, 0, sizeof *current); // clear old pos
	g_data.cells[newPos.x][newPos.y].played = 1;
	ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
}

void	communicate()
{
	t_msgbuf	msgbuf;
	pid_t		pid;

	ft_memset(&msgbuf, 0, sizeof msgbuf);
	msgq_getid();
	pid = getpid();
	printf("pid: %u\n", pid);
	while (1)
	{
		sleep(1);
		if (msgrcv(g_data.msgq_id, &msgbuf, sizeof msgbuf.mtext,
				(long)INT_MAX + pid, 0) == -1)
			perr_exit("communicate msgrcv");
		map_fill();
		if (sem_wait(g_data.sem) == -1)
			perr_exit("communicate sem_wait");
		move_player(pid);
		if (sem_post(g_data.sem) == -1)
			perr_exit("communicate sem_post");

		// if first player has played
		// send when every players has played
		if (playersPlayed() == 1) {
			msgbuf.mtype = INT_MAX;
			if (msgsnd(g_data.msgq_id, &msgbuf,
					sizeof msgbuf.mtext, 0) == -1) // all players played
				perr_exit("communicate msgsnd");
			printf("msgsnd end of turn");
			playersResetPlayed();
		}
	}
}

int		main(int ac, char **av)
{
	// add an erase arg to call ressources_erase
	/* ressources_erase(); exit(0); */
	ft_memset(&g_data, 0, sizeof g_data);
	map_init();
	get_args(ac, av);
	sighandle(); // clear only if last process quit
				 // handle too much processus error case
	map_get();
	map_fill();
	// error if player on case already exist
	map_addplayer();

	communicate();
	return (0);
}
