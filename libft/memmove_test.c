#include "libft.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	char	testA1[] = "abcdefg";
	char	testA2[] = "abcdefg";

	ft_memmove(testA1 + 1, testA1, 5);
	printf("A1: %s\n", testA1);
	ft_memmove(testA1 + 1, testA1, 0);
	memmove(testA2 + 1, testA2, 5);
	printf("A2: %s\n", testA2);
	memmove(testA2 + 1, testA2, 0);
	printf("A1: %s\n", testA1);
	printf("A2: %s\n", testA2);
	return 0;
}
