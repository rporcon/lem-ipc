#include "lemipc.h"

void 	setNewPosToEnemy(t_cell *newPos, int y, int x)
{
	t_cell 		newCell;

	newCell = g_data.cells[y][x];
	if (newCell.team_id == 0 && (*newPos).val > newCell.val)
	{
		newPos->val = newCell.val;
		newPos->y = y;
		newPos->x = x;
	}
}

t_cell 	nearestPosToEnemy(t_cell current)
{
	t_cell 		newPos;

	ft_memcpy(&newPos, &g_data.cells[current.y][current.x], sizeof newPos);
	newPos.val = UINT64_MAX;
	if (current.x + 1 < MAP_LEN)
		setNewPosToEnemy(&newPos, current.y, current.x + 1);
	if (current.x - 1 >= 0)
		setNewPosToEnemy(&newPos, current.y, current.x - 1);
	if (current.y + 1 < MAP_LEN)
		setNewPosToEnemy(&newPos, current.y + 1, current.x);
	if (current.y - 1 >= 0)
		setNewPosToEnemy(&newPos, current.y - 1, current.x);
	return (newPos);
}
