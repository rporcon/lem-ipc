#include "lemipc.h"

int 	enemiesAlive()
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].team_id > 0
					&& g_data.cells[inc.i][inc.j].team_id != g_data.team_id)
				return (1);
			inc.j++;
			inc.k++;
		}
		inc.i++;
	}
	return (0);
}

int 	allyNearEnemy()
{
	t_inc 			inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].team_id == g_data.team_id
					&& g_data.cells[inc.i][inc.j].pid != g_data.pid
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

void	setNewEnemyPos(t_cell newPos)
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].team_id > 0
					&& g_data.cells[inc.i][inc.j].enemy.pid == g_data.pid)
			{
				fprintf(stderr, "setting new enemy pos\n");
				g_data.cells[inc.i][inc.j].enemy.x = newPos.x;
				g_data.cells[inc.i][inc.j].enemy.y = newPos.y;
			}
			inc.j++;
		}
		inc.i++;
	}
}
