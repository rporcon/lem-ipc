#include "lemipc.h"

int		oneTeamAlive()
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

int		teamleader_exist()
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

uint32_t	playersNb()
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
