#include "lemipc.h"

int 	enemiesAlive()
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof inc);
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

void	setNewEnemyPos(pid_t pid, t_cell newPos)
{
	t_inc			inc;

	ft_memset(&inc, 0, sizeof inc);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].enemy != NULL) {
				fprintf(stderr, "pid: %d has enemy: %u\n", pid, g_data.cells[inc.i][inc.j].enemy->pid);
			}
			if (g_data.cells[inc.i][inc.j].team_id > 0
					&& g_data.cells[inc.i][inc.j].enemy != NULL
					&& g_data.cells[inc.i][inc.j].enemy->pid == pid)
			{
				break ;
				fprintf(stderr, "setting new enemy");
				g_data.cells[inc.i][inc.j].enemy->x = newPos.x;
				g_data.cells[inc.i][inc.j].enemy->y = newPos.y;
			}
			inc.j++;
			inc.k++;
		}
		inc.i++;
	}
}
