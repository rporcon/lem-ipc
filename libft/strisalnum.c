#include "libft.h"

int		strisalnum(char *str)
{
	size_t	i;
	int		isalnum;

	i = 0;
	isalnum = 1;
	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		if (ft_isalnum(str[i]) == 0)
		{
			isalnum = 0;
			break ;
		}
		i++;
	}
	return (isalnum);
}
