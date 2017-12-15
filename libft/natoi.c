/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_natoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:47:42 by rporcon           #+#    #+#             */
/*   Updated: 2017/08/12 15:47:44 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		natoi(const char *str, unsigned int len)
{
	int				negative;
	int				total;
	unsigned int	i;

	negative = 0;
	i = 0;
	total = 0;
	negative = str[i] == '-' ? 1 : 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && i < len)
	{
		total = total * 10 + str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-total);
	else
		return (total);
}
