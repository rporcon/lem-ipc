#include "libft.h"

int		strisdigit(char *str)
{
	size_t	i;
	int		isdigit;

	i = 0;
	isdigit = 1;
	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		if (ft_isdigit(str[i]) == 0)
		{
			isdigit = 0;
			break ;
		}
		i++;
	}
	return (isdigit);
}
