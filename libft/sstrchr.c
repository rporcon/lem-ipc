#include "libft.h"

unsigned char sstrchr(char **sstr, char *chr)
{
	if (sstr == NULL)
		return (0);
	for (size_t i = 0; sstr[i] != NULL; i++) {
		if (ft_strcmp(sstr[i], chr) == 0)
			return (1);
	}
	return (0);
}
