#include "lemipc.h"

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

t_enemy 	cellToEnemy(t_cell c)
{
	t_enemy enemy;

	enemy.x = c.x;
	enemy.y = c.y;
	enemy.pid = c.pid;
	return (enemy);
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
