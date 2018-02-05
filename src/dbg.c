/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:26:36 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/05 09:28:14 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	dbg_moveplayer(t_cell *current)
{
	printf("{pid: %u, teamid: %u} current pos: [%lld][%lld], current enemy"
			"[%lld][%lld] pid %u , val: %llu\n------\n", g_data.pid,
			g_data.team_id, current->y, current->x, current->enemy.y,
			current->enemy.x, current->enemy.pid, current->val);
}
