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

t_enemy enemy_chr(t_cell current)
{
	t_cell			c_enemies[ENEMY_SIZE];
	t_cell 			c_enemy;
	t_enemy			enemy;
	uint32_t		enemy_nb;
	t_inc 			inc;

	ft_memset(&c_enemies, 0, sizeof c_enemies);
	ft_memset(&inc, 0, sizeof inc);
	fill_enemies(c_enemies, current, &enemy_nb, inc);
	assert(enemy_nb > 0); //
	c_enemy = c_enemies[0];
	inc.i = 1;
	while (inc.i < enemy_nb)
	{
		if (c_enemies[inc.i].val < c_enemy.val)
			c_enemy = c_enemies[inc.i];
		inc.i++;
	}
	enemy = cellToEnemy(c_enemy);
	printf("common enemy is: %d\n", enemy.pid);
	return (enemy);
}

void 	setNewPosToEnemy(t_cell *newPos, int y, int x)
{
	t_cell 		newCell;

	newCell = g_data.cells[y][x];
	if (newCell.val != 0 && (*newPos).val > newCell.val)
	{
		newPos->val = newCell.val;
		newPos->y = y;
		newPos->x = x;
	}
}

t_cell 	nearestPosToEnemy(t_cell current)
{
	t_cell 		newPos;

	ft_memcpy(&newPos, &g_data.cells[current.y][current.x], sizeof newPos);
	newPos.val = UINT64_MAX;
	if (current.x + 1 < MAP_LEN)
		setNewPosToEnemy(&newPos, current.y, current.x + 1);
	if (current.x - 1 >= 0)
		setNewPosToEnemy(&newPos, current.y, current.x - 1);
	if (current.y + 1 < MAP_LEN)
		setNewPosToEnemy(&newPos, current.y + 1, current.x);
	if (current.y - 1 >= 0)
		setNewPosToEnemy(&newPos, current.y - 1, current.x);
	return (newPos);
}

/* void	testt(pid_t pid) */
/* { */
/* 	t_inc			inc; */

/* 	ft_memset(&inc, 0, sizeof inc); */
/* 	while (inc.i < MAP_LEN) */
/* 	{ */
/* 		inc.j = 0; */
/* 		while (inc.j < MAP_LEN) */
/* 		{ */
/* 			fprintf(stderr, "[%lld][%lld]", inc.i, inc.j); */
/* 			if (g_data.cells[inc.i][inc.j].enemy != NULL) { */
/* 				fprintf(stderr, "pid: %d has enemy: %u\n", 	pid, */
/* 					g_data.cells[inc.i][inc.j].enemy->pid); */
/* 			} */
/* 			inc.j++; */
/* 		} */
/* 		inc.i++; */
/* 	} */
/* } */


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
				g_data.cells[inc.i][inc.j].val = abs((int)(current.enemy.x -
					g_data.cells[inc.i][inc.j].x)) + abs((int)(
					current.enemy.y - g_data.cells[inc.i][inc.j].y));
			}
			inc.j++;
		}
		inc.i++;
	}
	return (nearestPosToEnemy(current));
}

int 	allyNearEnemy(pid_t pid)
{
	t_inc 			inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].team_id == g_data.team_id
					&& g_data.cells[inc.i][inc.j].pid != pid
					&& g_data.cells[inc.i][inc.j].val == 1)
				return (1);
			inc.j++;
		}
		inc.i++;
	}
	return (0);
}

void 	allyClearEnemySet(t_enemy enemy)
{
	t_inc 			inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].team_id == g_data.team_id
					&& enemy.pid == g_data.cells[inc.i][inc.j].enemy.pid)
				g_data.cells[inc.i][inc.j].enemy_set = 0;
			inc.j++;
		}
		inc.i++;
	}
}


void	move_player(pid_t pid)
{
	t_msgbuf	msgbuf;
	t_cell		*current;
	t_cell 		newPos;

	map_currentcell(pid, &current);
	/* printf("current cell: [%lld][%lld]\n", current->y, current->x); */
	if (teamleader_exist() == 0) {
	 	current->team_leader = 1;
		ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE); // with semaphore remove ?
	}
	if (current->enemy_set == 0 && current->team_leader == 1)
	{
		// has team leader to wait other allies to send target ?
		while (enemiesAlive() == 0) {
			ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
			sleep(1);
		}
		current->enemy = enemy_chr(*current);
		current->enemy_set = 1;
		printf("[team leader] pid: {%u} send ennemy[%lld][%lld](%u)", pid,
				current->enemy.y, current->enemy.x, current->enemy.pid);
		// send ennemy target to same team player
		send_target(current->enemy);
	}
	else if (current->enemy_set == 0)
	{
		printf("[non team leader], rcv on: [%lu], pid: {%u}\n", (long)INT_MAX + pid, pid);
		if (msgrcv(g_data.msgq_id, &msgbuf, sizeof msgbuf.mtext,
				g_data.team_id, 0) == -1)
			perr_exit("move_player msgrcv");
		current->enemy = *((t_enemy *)msgbuf.mtext);
		printf("received ennemy: %d\n", current->enemy.pid);
		current->enemy_set = 1;
	}
	newPos = moveToEnemy(*current);
	printf("{pid: %u} currentPos: [%lld][%lld], newPos: [%lld][%lld], val: %llu\n",
			pid, current->y, current->x, newPos.y, newPos.x, newPos.val);
	printf("enemy: [%lld][%lld] (pid: %u) \n", current->enemy.y, current->enemy.x, current->enemy.pid);
	if (newPos.val == 1 && allyNearEnemy(pid) == 1)
	{
		printf("clear enemy: [%lld][%lld]\n", current->enemy.y, current->enemy.x);
		ft_memset(&g_data.cells[current->enemy.y][current->enemy.x],
			0, sizeof current->enemy); // sigterm process
		allyClearEnemySet(current->enemy);
	}
	if (enemiesAlive() == 0) {
		printf("End of game\n");
		exit(1);
	}
	setNewEnemyPos(pid, newPos);
	g_data.cells[newPos.y][newPos.x] = newPos;
	// reset enemy pos (verify if enemy pos has changed)
	ft_memset(current, 0, sizeof *current); // clear old pos
	g_data.cells[newPos.y][newPos.x].played = 1;
	printf("played ~!\n");
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
		/* sleep(1); */
		if (msgrcv(g_data.msgq_id, &msgbuf, sizeof msgbuf.mtext,
				(long)INT_MAX + pid, 0) == -1)
			perr_exit("communicate msgrcv");
		map_fill();
		if (sem_wait(g_data.sem) == -1)
			perr_exit("communicate sem_wait");
		move_player(pid);
		if (sem_post(g_data.sem) == -1)
			perr_exit("communicate sem_post");

		if (playersPlayed() == 1) {
			msgbuf.mtype = INT_MAX;
			if (msgsnd(g_data.msgq_id, &msgbuf,
					sizeof msgbuf.mtext, 0) == -1) // all players played
				perr_exit("communicate msgsnd");
			printf("msgsnd end of turn\n");
			playersResetPlayed();
			ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE); // semaphore ?
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
