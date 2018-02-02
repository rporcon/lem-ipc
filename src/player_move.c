#include "lemipc.h"

void	init_teamleader(t_cell *current)
{
	while (enemies_alive() == 0) {
		ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
		usleep(100000);
	}
	current->enemy = enemy_chr(*current);
	current->enemy_set = 1;
	if (DBG == 1)
	{
		printf("[TL] g_data.pid: {%u} send ennemy[%lld][%lld](%u)", g_data.pid,
			current->enemy.y, current->enemy.x, current->enemy.pid);
	}
	send_target(current->enemy);
}

void 	init_enemy(t_cell *current)
{
	if (msgrcv(g_data.msgq_id, &g_data.msgbuf, sizeof g_data.msgbuf.mtext,
			g_data.team_id, 0) == -1)
		perr_exit("move_player msgrcv");
	current->enemy = *((t_enemy *)g_data.msgbuf.mtext);
	if (DBG == 1)
	{
		printf("[non TL], pid: {%u} received ennemy: %d\n",
			g_data.pid, current->enemy.pid);
	}
	current->enemy_set = 1;
}

void	setNewCurrentPos(t_cell *current)
{
	t_cell 		newPos;

	newPos = nearestPosToEnemy(*current);
	if (DBG == 1)
	{
		printf("{pid: %u} newPos: [%lld][%lld], val: %llu\n",
			g_data.pid, newPos.y, newPos.x, newPos.val);
		printf("enemy: [%lld][%lld] (pid: %u)\n",
			current->enemy.y, current->enemy.x, current->enemy.pid);
	}
	set_newenemy_pos(newPos);
	g_data.cells[newPos.y][newPos.x] = newPos;
	ft_memset(current, 0, sizeof *current); // clear old pos
	g_data.cells[newPos.y][newPos.x].played = 1;
}

void	clearCurrent(t_cell *current)
{
	if (DBG == 1)
		printf("clear current: [%lld][%lld]\n", current->y, current->x);
	ft_memset(current, 0, sizeof *current);
	ally_clear_enemyset();
	if (oneTeamAlive() == 1) {
		g_data.msgbuf.mtype = INT_MAX;
		ft_strcpy(g_data.msgbuf.mtext, "EndOfGame");
		ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
		if (msgsnd(g_data.msgq_id, &g_data.msgbuf,
				sizeof g_data.msgbuf.mtext, 0) == -1)
			perr_exit("[msgsnd] endOfGame");
		sleep(3);
		ressources_erase();
	}
	exit(0);
}

void	move_player()
{
	t_cell		*current;

	map_currentcell(&current);
	if (teamleader_exist() == 0) {
	 	current->team_leader = 1;
		ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
	}
	if (current->enemy_set == 0 && current->team_leader == 1)
		init_teamleader(current);
	else if (current->enemy_set == 0)
		init_enemy(current);
	set_currentval(*current);
	if (two_enemies_near(*current) == 1)
		clearCurrent(current);
	set_to_enemyval(*current);
	if (current->val != 1)
		setNewCurrentPos(current);
	else
		current->played = 1;
	if (DBG == 1)
	{
		printf("{pid: %u} currentPos: [%lld][%lld], val: %llu\n",
			g_data.pid, current->y, current->x, current->val);
	}
	ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
}
