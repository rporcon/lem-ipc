/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cells_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 13:32:34 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/02 13:51:02 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	reset_cells_val(void)
{
	t_inc	inc;

	ft_memset(&inc, 0, sizeof(inc));
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

void	set_currentval(t_cell current)
{
	t_inc	inc;

	ft_memset(&inc, 0, sizeof(inc));
	reset_cells_val();
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].val == 0)
			{
				if (abs((int)(current.x - g_data.cells[inc.i][inc.j].x)) == 1
						&& abs((int)(current.y -
						g_data.cells[inc.i][inc.j].y)) == 1)
					g_data.cells[inc.i][inc.j].val = 1;
				else
					g_data.cells[inc.i][inc.j].val = abs((int)(current.x -
						g_data.cells[inc.i][inc.j].x)) + abs((int)(current.y -
						g_data.cells[inc.i][inc.j].y));
			}
			inc.j++;
		}
		inc.i++;
	}
}

void	set_to_enemyval(t_cell current)
{
	t_inc	inc;

	ft_memset(&inc, 0, sizeof(inc));
	reset_cells_val();
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].val == 0)
			{
				if (abs((int)(current.enemy.x - g_data.cells[inc.i][inc.j].x))
						== 1 && abs((int)(current.enemy.y -
								g_data.cells[inc.i][inc.j].y)) == 1)
					g_data.cells[inc.i][inc.j].val = 1;
				else
					g_data.cells[inc.i][inc.j].val = abs((int)(current.enemy.x
						- g_data.cells[inc.i][inc.j].x)) + abs((int)(
						current.enemy.y - g_data.cells[inc.i][inc.j].y));
			}
			inc.j++;
		}
		inc.i++;
	}
}
