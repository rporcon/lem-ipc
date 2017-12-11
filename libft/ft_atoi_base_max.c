/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:13:45 by rporcon           #+#    #+#             */
/*   Updated: 2017/06/09 16:19:13 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_atoi_base_max(const char *str, int base)
{
	size_t	total;
	size_t	i;

	total = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
		i++;
	i += ft_strncmp("0x", str, 2) == 0 ? 2 : 0;
	i += str[i] == '+' ? 1 : 0;
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
	return (total);
}
