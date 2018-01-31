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

