/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moveto.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:39:39 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/12 11:59:13 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	set_newpos_toenemy(t_cell *new_pos, int y, int x)
{
	t_cell	new_cell;

	new_cell = g_data.cells[y][x];
	if (new_cell.team_id == 0)
	{
		if ((*new_pos).val > new_cell.val)
		{
			new_pos->val = new_cell.val;
			new_pos->y = y;
			new_pos->x = x;
		}
		else if ((*new_pos).val == new_cell.val && rand() % 2 == 0)
		{
			new_pos->val = new_cell.val;
			new_pos->y = y;
			new_pos->x = x;
		}
	}
}

t_cell	nearest_pos_toenemy(t_cell current)
{
	t_cell	new_pos;

	ft_memcpy(&new_pos, &g_data.cells[current.y][current.x], sizeof(new_pos));
	new_pos.val = UINT64_MAX;
	if (current.x + 1 < MAP_LEN)
		set_newpos_toenemy(&new_pos, current.y, current.x + 1);
	if (current.x - 1 >= 0)
		set_newpos_toenemy(&new_pos, current.y, current.x - 1);
	if (current.y + 1 < MAP_LEN)
		set_newpos_toenemy(&new_pos, current.y + 1, current.x);
	if (current.y - 1 >= 0)
		set_newpos_toenemy(&new_pos, current.y - 1, current.x);
	return (new_pos);
}
