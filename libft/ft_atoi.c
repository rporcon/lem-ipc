/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:08:59 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/30 13:11:17 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		negative;
	int		total;
	int		i;

	negative = 0;
	i = 0;
	total = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\f')
		i++;
	negative = str[i] == '-' ? 1 : 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-total);
	else
		return (total);
}
