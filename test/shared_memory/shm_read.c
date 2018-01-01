#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>

void        perr_exit(const char *str)
{
	perror(str);
	exit(1);
}

int main()
{
	int				fd;
	void			*mem;
	struct timeval	tv_start;
	struct timeval	tv_end;
	/* char			on = 0; */

	gettimeofday(&tv_start, NULL);
	if ((fd = shm_open("/shm-test", O_RDWR, 0666))
			== -1)
		perr_exit("shm_open");
	if ((mem = mmap(NULL, getpagesize(), PROT_READ
					| PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED)
			perr_exit("read mmap");
	while (1) {
		gettimeofday(&tv_end, NULL);
		memcpy(mem, "4242", 4);
		/* if (tv_end.tv_sec - tv_start.tv_sec == 5 && on == 0) { */
		/* 	memcpy(mem, "4242", 4); */
		/* } */
		printf("[%s]\n", mem);
	}
	return (0);
}
