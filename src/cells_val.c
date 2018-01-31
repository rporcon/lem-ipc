#include "lemipc.h"

void 	resetCellsVal()
{
	t_inc 			inc;

	ft_memset(&inc, 0, sizeof inc);
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

void 	setCurrentVal(t_cell current)
{
	t_inc 			inc;

	ft_memset(&inc, 0, sizeof inc);
	resetCellsVal();
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].val == 0)
			{
				if (abs((int)(current.x - g_data.cells[inc.i][inc.j].x))
						== 1 && abs((int)(current.y -
						g_data.cells[inc.i][inc.j].y)) == 1)
					g_data.cells[inc.i][inc.j].val = 1;
				else {
					g_data.cells[inc.i][inc.j].val = abs((int)(current.x -
						g_data.cells[inc.i][inc.j].x)) + abs((int)(current.y -
						g_data.cells[inc.i][inc.j].y));
				}
			}
			inc.j++;
		}
		inc.i++;
	}
}

void 	setToEnemyVal(t_cell current)
{
	t_inc 			inc;

	ft_memset(&inc, 0, sizeof inc);
	resetCellsVal();
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
				else {
					g_data.cells[inc.i][inc.j].val = abs((int)(current.enemy.x -
						g_data.cells[inc.i][inc.j].x)) + abs((int)(
						current.enemy.y - g_data.cells[inc.i][inc.j].y));
				}
			}
			inc.j++;
		}
		inc.i++;
	}
}

