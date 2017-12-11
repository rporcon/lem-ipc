#include "libft.h"

void	sstrfree(char **sstr)
{
	int i;

	if (sstr == NULL)
		return ;
	i = 0;
	while (sstr[i])
	{
		free(sstr[i]);
		i++;
	}
	free(sstr);
}
