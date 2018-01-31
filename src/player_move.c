#include "lemipc.h"

void	move_player(pid_t pid)
{
	t_msgbuf	msgbuf;
	t_cell		*current;
	t_cell 		newPos;

	map_currentcell(pid, &current);
	if (teamleader_exist() == 0) {
	 	current->team_leader = 1;
		ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE); // with semaphore remove ?
	}
	if (current->enemy_set == 0 && current->team_leader == 1)
	{
		while (enemiesAlive() == 0) {
			ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
			sleep(1); // usleep 1/10 second
		}
		current->enemy = enemy_chr(*current);
		current->enemy_set = 1;
		printf("[TL] pid: {%u} send ennemy[%lld][%lld](%u)", pid,
				current->enemy.y, current->enemy.x, current->enemy.pid);
		send_target(current->enemy);
	}
	else if (current->enemy_set == 0)
	{
		if (msgrcv(g_data.msgq_id, &msgbuf, sizeof msgbuf.mtext,
				g_data.team_id, 0) == -1)
			perr_exit("move_player msgrcv");
		current->enemy = *((t_enemy *)msgbuf.mtext);
		printf("[non TL], pid: {%u} received ennemy: %d\n", pid, current->enemy.pid);
		current->enemy_set = 1;
	}
	setVal(*current);
	if (current->val == 1 && allyNearEnemy(pid) == 1)
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
	if (current->val != 1)
	{
		newPos = nearestPosToEnemy(*current);
		printf("{pid: %u} newPos: [%lld][%lld], val: %llu\n", pid, newPos.y, newPos.x, newPos.val);
		printf("enemy: [%lld][%lld] (pid: %u) \n", current->enemy.y, current->enemy.x, current->enemy.pid);
		setNewEnemyPos(pid, newPos);
		g_data.cells[newPos.y][newPos.x] = newPos;
		ft_memset(current, 0, sizeof *current); // clear old pos
		g_data.cells[newPos.y][newPos.x].played = 1;
	}
	else {
		printf("{pid: %u} currentPos: [%lld][%lld], val: %llu\n", pid, current->y, current->x, current->val);
		current->played = 1;
	}
	printf("played ~!\n");
	ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
}
