#include "seqnum.h"

int main(int argc, char *argv[])
{
	sem_t   *mysem;

	if ((mysem = sem_open("/sem-test", 0)) == SEM_FAILED) {
		perror("sem_open"); exit(1);
	}
	if (sem_wait(mysem) == -1) {
		perror("sem_wait"); exit(1);	
	};
	printf("sleep\n");
	sleep(5);
	printf("sleep finished\n");
	if (sem_post(mysem) == -1) {
		perror("sem_post"); exit(1);	
	}
	return 0;
}
