#include <sys/mman.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct shmbuf {
	sem_t sem; // semaphore to protect access
	int seqnum;
};

