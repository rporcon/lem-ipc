#include "libft.h"

int		strisalpha(char *str)
{
	size_t	i;
	int		isalpha;

	i = 0;
	isalpha = 1;
	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		if (ft_isalpha(str[i]) == 0)
		{
			isalpha = 0;
			break ;
		}
		i++;
	}
	return (isalpha);
}
