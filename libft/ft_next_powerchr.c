/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_powerchr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:32:28 by rporcon           #+#    #+#             */
/*   Updated: 2017/06/09 16:14:50 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_next_powerchr(size_t num, size_t power)
{
	size_t	next_power;

	if (num % power == 0)
		next_power = num;
	else
		next_power = num + (power - ((num + power) % power));
	return (next_power);
}
