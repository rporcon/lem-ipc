#include "lemipc.h"

void	msgq_getid(int *msgq_id)
{
	key_t	key;
	if ((key = ftok("./src/msg.c", '*')) == -1)
		perr_exit("msg_getid ftok");
	if ((*msgq_id = msgget(key, 0644 | IPC_CREAT)) == -1)
		perr_exit("msg_getid msgget");
}
