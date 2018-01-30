#include "lemipc.h"

void	msgq_getid()
{
	key_t	key;

	if ((key = ftok("./src/msg.c", '*')) == -1)
		perr_exit("msg_getid ftok");
	if ((g_data.msgq_id = msgget(key, 0644 | IPC_CREAT)) == -1)
		perr_exit("msg_getid msgget");
}

void	send_target(t_enemy enemy)
{
	t_inc		inc;
	t_msgbuf	msgbuf;

	ft_memset(&inc, 0, sizeof inc);
	ft_memset(&msgbuf, 0, sizeof msgbuf);
	while (inc.i < MAP_LEN)
	{
		inc.j = 0;
		while (inc.j < MAP_LEN)
		{
			if (g_data.cells[inc.i][inc.j].team_id == g_data.team_id
					&& g_data.cells[inc.i][inc.j].team_leader == 0)
			{
				msgbuf.mtype = g_data.team_id;
				ft_memcpy(msgbuf.mtext, &enemy, sizeof enemy);
				printf(" to: %d team players\n", g_data.team_id);
				if (msgsnd(g_data.msgq_id, &msgbuf, sizeof msgbuf.mtext, 0) == -1)
					perr_exit("send_target msgsnd");
			}
			inc.j++;
			inc.k++;
		}
		inc.i++;
	}
}
