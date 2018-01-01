#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>

void        perr_exit(const char *str)
{
	perror(str);
	exit(1);
}

int main()
{
	int		fd;
	void	*mem;
	size_t	len = getpagesize();

	shm_unlink("/shm-test");
	if ((fd = shm_open("/shm-test", O_RDWR | O_CREAT, 0666))
			== -1)
		perr_exit("shm_open");
	if (ftruncate(fd, len) == -1)
		    perr_exit("map_get ftruncate");
	if ((mem = mmap(NULL, len, PROT_READ
					| PROT_WRITE, MAP_SHARED, fd, 0)) == (void *)-1)
			perr_exit("create mmap");
	close(fd);
	memset(mem, 0, len);
	memcpy(mem, "ABCDEFGH", 9);
	return (0);
}
