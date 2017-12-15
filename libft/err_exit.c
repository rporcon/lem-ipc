#include "libft.h"

void		err_exit(const char *err_msg, int status_code)
{
	if (err_msg != NULL)
		fprintf(stderr, "Error: %s\n", err_msg);
	exit(status_code);
}
