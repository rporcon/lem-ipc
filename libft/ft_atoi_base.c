/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:14:36 by rporcon           #+#    #+#             */
/*   Updated: 2017/06/09 16:18:13 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_atoi_base_init(const char *str, int *negative, int *i)
{
	*negative = 0;
	*i = 0;
	while (str[*i] == ' ' || str[*i] == '\n' || str[*i] == '\v' ||
			str[*i] == '\t' || str[*i] == '\r' || str[*i] == '\f')
		(*i)++;
	*i += ft_strncmp("0x", str, 2) == 0 ? 2 : 0;
	*negative = str[*i] == '-' ? 1 : 0;
	if (str[*i] == '+' || str[*i] == '-')
		(*i)++;
}

int		ft_atoi_base(const char *str, int base)
{
	int		negative;
	int		total;
	int		i;

	ft_atoi_base_init(str, &negative, &i);
	total = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			total = (total * base) + str[i] - '0';
		else if ((str[i] >= 'A' && str[i] <= 'F') ||
			(str[i] >= 'a' && str[i] <= 'f'))
			total = (ft_isupper(str[i])) ? (total * base) + str[i] -
				('A' - 10) : (total * base) + str[i] - ('a' - 10);
		else
			break ;
		i++;
	}
	if (negative == 1)
		return (-total);
	else
		return (total);
}
