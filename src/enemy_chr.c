/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:36:07 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/02 14:39:21 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void		fill_enemies(t_cell enemies[ENEMY_SIZE], t_cell current,
			uint32_t *enemy_nb, t_inc inc)
{
	reset_cells_val();
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

t_enemy		cell_to_enemy(t_cell c)
{
	t_enemy		enemy;

	enemy.x = c.x;
	enemy.y = c.y;
	enemy.pid = c.pid;
	return (enemy);
}

t_enemy		enemy_chr(t_cell current)
{
	t_cell			c_enemies[ENEMY_SIZE];
	t_cell			c_enemy;
	t_enemy			enemy;
	uint32_t		enemy_nb;
	t_inc			inc;

	ft_memset(&c_enemies, 0, sizeof(c_enemies));
	ft_memset(&inc, 0, sizeof(inc));
	fill_enemies(c_enemies, current, &enemy_nb, inc);
	if (DBG == 1)
		assert(enemy_nb > 0);
	c_enemy = c_enemies[0];
	inc.i = 1;
	while (inc.i < enemy_nb)
	{
		if (c_enemies[inc.i].val < c_enemy.val)
			c_enemy = c_enemies[inc.i];
		inc.i++;
	}
	enemy = cell_to_enemy(c_enemy);
	if (DBG == 1)
		printf("common enemy is: %d\n", enemy.pid);
	return (enemy);
}
