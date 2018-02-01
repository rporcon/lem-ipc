#include "lemipc.h"

void	init_teamleader(t_cell *current)
{
	while (enemiesAlive() == 0) {
		ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
		sleep(1); // usleep 1/10 second
	}
	current->enemy = enemy_chr(*current);
	current->enemy_set = 1;
	printf("[TL] g_data.pid: {%u} send ennemy[%lld][%lld](%u)", g_data.pid,
			current->enemy.y, current->enemy.x, current->enemy.pid);
	send_target(current->enemy);
}

void 	init_enemy(t_cell *current)
{
	if (msgrcv(g_data.msgq_id, &g_data.msgbuf, sizeof g_data.msgbuf.mtext,
			g_data.team_id, 0) == -1)
		perr_exit("move_player msgrcv");
	current->enemy = *((t_enemy *)g_data.msgbuf.mtext);
	printf("[non TL], pid: {%u} received ennemy: %d\n", g_data.pid, current->enemy.pid);
	current->enemy_set = 1;
}

void	setNewCurrentPos(t_cell *current)
{
	t_cell 		newPos;

	newPos = nearestPosToEnemy(*current);
	printf("{pid: %u} newPos: [%lld][%lld], val: %llu\n", g_data.pid, newPos.y, newPos.x, newPos.val);
	printf("enemy: [%lld][%lld] (pid: %u) \n", current->enemy.y, current->enemy.x, current->enemy.pid);
	setNewEnemyPos(newPos);
	g_data.cells[newPos.y][newPos.x] = newPos;
	ft_memset(current, 0, sizeof *current); // clear old pos
	g_data.cells[newPos.y][newPos.x].played = 1;
}

void	move_player()
{
	t_cell		*current;

	map_currentcell(&current);
	if (teamleader_exist() == 0) {
	 	current->team_leader = 1;
		ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE); //sem
	}
	if (current->enemy_set == 0 && current->team_leader == 1)
		init_teamleader(current);
	else if (current->enemy_set == 0)
		init_enemy(current);
	setCurrentVal(*current);
	if (twoEnemiesNear(*current) == 1)
	{
		printf("clear current: [%lld][%lld]\n", current->y, current->x);
		ft_memset(current, 0, sizeof *current);
		allyClearEnemySet();
		if (oneTeamAlive() == 1) {
			printf("!!!!\n");
			g_data.msgbuf.mtype = INT_MAX;
			/* ft_memset(g_data.msgbuf.mtext, 0, sizeof g_data.msgbuf.mtext); */
			ft_strcpy(g_data.msgbuf.mtext, "EndOfGame");
			ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
			if (msgsnd(g_data.msgq_id, &g_data.msgbuf,
					sizeof g_data.msgbuf.mtext, 0) == -1)
				perr_exit("[msgsnd] endOfGame");
			printf("End of game\n");
			sleep(1);
			/* ressources_erase(); */
		}
		exit(0);
	}
	setToEnemyVal(*current);
	if (current->val != 1)
		setNewCurrentPos(current);
	else {
		printf("{pid: %u} currentPos: [%lld][%lld], val: %llu\n", g_data.pid, current->y, current->x, current->val);
		current->played = 1;
	}
	printf("played ~!\n");
	ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);//sem
}
