#include "seqnum.h"

int main(int argc, char *argv[])
{
	sem_t	*mysem;

	if (sem_unlink("/sem-test") == -1)
		fprintf(stderr, "cannot unlink /sem-test\n");
	if ((mysem = sem_open("/sem-test", O_CREAT, 0666, 1)) == SEM_FAILED) {
		perror("sem_open"); exit(1);
	}
	else
		printf("create /sem-test semaphore\n");
	return 0;
}
