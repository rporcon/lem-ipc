#include "lemipc.h"

int 	playersPlayed()
{
	t_inc	inc;

	ft_memset(&inc, 0, sizeof inc);
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
	printf("all players have played\n");
	return (1);
}

void 	playersResetPlayed()
{
	t_inc	inc;
	size_t 	nb;

	ft_memset(&inc, 0, sizeof inc);
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

uint32_t	playersPlayedNb()
{
	t_inc	inc;
	size_t 	nb;

	ft_memset(&inc, 0, sizeof inc);
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

int		teamleader_exist()
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof inc);
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

	ft_memset(&inc, 0, sizeof inc);
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
