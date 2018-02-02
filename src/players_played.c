/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_played.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:53:25 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/02 14:55:57 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int			players_played(void)
{
	t_inc	inc;

	ft_memset(&inc, 0, sizeof(inc));
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].team_id > 0 &&
					g_data.cells[inc.i][inc.j].played == 0)
				return (0);
			inc.j++;
		}
		inc.i++;
	}
	if (DBG == 1)
		printf("all players have played\n");
	return (1);
}

void		players_reset_played(void)
{
	t_inc	inc;
	size_t	nb;

	ft_memset(&inc, 0, sizeof(inc));
	nb = 0;
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].team_id > 0 &&
					g_data.cells[inc.i][inc.j].played == 1)
				g_data.cells[inc.i][inc.j].played = 0;
			inc.j++;
		}
		inc.i++;
	}
}

uint32_t	players_played_nb(void)
{
	t_inc	inc;
	size_t	nb;

	ft_memset(&inc, 0, sizeof(inc));
	nb = 0;
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].team_id > 0
					&& g_data.cells[inc.i][inc.j].played == 1)
				nb++;
			inc.j++;
		}
		inc.i++;
	}
	return (nb);
}
