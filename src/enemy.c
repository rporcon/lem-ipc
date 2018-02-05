/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 13:51:19 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/05 09:11:51 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		enemies_alive(void)
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof(inc));
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

int		surrounded_by_enemies(t_inc inc, uint32_t enemies_team[8])
{
	int			i;
	t_enemy		enemy;

	enemy = g_data.cells[inc.i][inc.j].enemy;
	if (enemy.pid == g_data.pid
			&& g_data.cells[inc.i][inc.j].val == 1)
	{
		i = 0;
		while (i < inc.k)
		{
			if (g_data.cells[enemy.y][enemy.x].team_id == enemies_team[i])
				return (1);
			i++;
		}
		enemies_team[inc.k] = g_data.cells[enemy.y][enemy.x].team_id;
		inc.k++;
	}
	return (0);
}

int		two_enemies_near(void)
{
	t_inc		inc;
	uint32_t	enemies_team[8];

	ft_memset(&inc, 0, sizeof(inc));
	ft_memset(&enemies_team, 0, sizeof(enemies_team));
	print_cells();
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (surrounded_by_enemies(inc, enemies_team) == 1)
				return (1);
			inc.j++;
		}
		inc.i++;
	}
	return (0);
}

void	ally_clear_tlenemyset(void)
{
	t_inc	inc;

	ft_memset(&inc, 0, sizeof(inc));
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.pid == g_data.cells[inc.i][inc.j].enemy.pid)
			{
				g_data.cells[inc.i][inc.j].enemy_set = 0;
				if (g_data.cells[inc.i][inc.j].team_leader == 1)
					g_data.cells[inc.i][inc.j].team_leader = 0;
			}
			inc.j++;
		}
		inc.i++;
	}
}

void	set_newenemy_pos(t_cell new_pos)
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof(inc));
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].team_id > 0
					&& g_data.cells[inc.i][inc.j].enemy.pid == g_data.pid)
			{
				g_data.cells[inc.i][inc.j].enemy.x = new_pos.x;
				g_data.cells[inc.i][inc.j].enemy.y = new_pos.y;
			}
			inc.j++;
		}
		inc.i++;
	}
}
