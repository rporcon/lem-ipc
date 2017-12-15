#include "libft.h"

void		perr_exit(const char *str)
{
	perror(str);
	exit(1);
}
