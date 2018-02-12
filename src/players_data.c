/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:51:21 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/12 14:09:19 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int			oneteam_alive(void)
{
	t_inc		inc;
	uint32_t	teamid;

	ft_memset(&inc, 0, sizeof(inc));
	teamid = 0;
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].team_id > 0)
			{
				if (teamid == 0)
					teamid = g_data.cells[inc.i][inc.j].team_id;
				else if (teamid != g_data.cells[inc.i][inc.j].team_id)
					return (0);
			}
			inc.j++;
		}
		inc.i++;
	}
	return (1);
}

int			teamleader_exist(void)
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof(inc));
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].team_id == g_data.team_id
					&& g_data.cells[inc.i][inc.j].team_leader == 1)
				return (1);
			inc.j++;
			inc.k++;
		}
		inc.i++;
	}
	return (0);
}

uint32_t	players_nb(void)
{
	t_inc			inc;
	uint32_t		players_nb;

	ft_memset(&inc, 0, sizeof(inc));
	players_nb = 0;
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].team_id > 0)
				players_nb++;
			inc.j++;
		}
		inc.i++;
	}
	return (players_nb);
}

void		end_of_game(void)
{
	g_data.msgbuf.mtype = INT_MAX;
	ft_strcpy(g_data.msgbuf.mtext, "EndOfGame");
	if (msgsnd(g_data.msgq_id, &g_data.msgbuf,
			sizeof(g_data.msgbuf.mtext), 0) == -1)
		perr_exit("[msgsnd] endOfGame");
	ressources_erase();
}
