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

/* int		addSurroundedEnemy(t_enemy enemy, uint32_t enemies_team[8], */
/* 			int64_t *k) */
/* { */
/* 	int		i; */

/* 	i = 0; */
/* 	while (i < 8) */
/* 	{ */
/* 		if (g_data.cells[enemy.y][enemy.x].team_id */
/* 				== enemies_team[i]) */
/* 			return (1); */
/* 		i++; */
/* 	} */
/* 	enemies_team[*k] = g_data.cells[enemy.y][enemy.x].team_id; */
/* 	(*k)++; */
/* 	return (0); */
/* } */

int		twoEnemiesNear()
{
	t_inc 		inc;
	t_enemy 	enemy;
	uint32_t	enemies_team[8];
	int			i;

	ft_memset(&inc, 0, sizeof inc);
	ft_memset(&enemies_team, 0, sizeof enemies_team);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			/* printf("[%lld][%lld] val: %llu\n", inc.i, inc.j, */
			/* 		g_data.cells[inc.i][inc.j].val); */
			enemy = g_data.cells[inc.i][inc.j].enemy;
			if (enemy.pid == g_data.pid
					&& g_data.cells[inc.i][inc.j].val == 1)
			{
				i = 0;
				/* printf("enemy[%lld][%lld] team_id: %u\n", enemy.y, enemy.x, */
				/* 		g_data.cells[enemy.y][enemy.x].team_id); */
				while (i < 8)
				{
					if (g_data.cells[enemy.y][enemy.x].team_id
							== enemies_team[i])
						return (1);
					i++;
				}
				enemies_team[inc.k] = g_data.cells[enemy.y][enemy.x].team_id;
				inc.k++;
			}
			inc.j++;
		}
		inc.i++;
	}
	return (0);
}

void 	allyClearEnemySet()
{
	t_inc 			inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.pid == g_data.cells[inc.i][inc.j].enemy.pid)
				g_data.cells[inc.i][inc.j].enemy_set = 0;
			/* if (g_data.cells[inc.i][inc.j].team_id == g_data.team_id */
			/* 		&& enemy.pid == g_data.cells[inc.i][inc.j].enemy.pid) */
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
