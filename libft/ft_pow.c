/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 10:01:06 by rporcon           #+#    #+#             */
/*   Updated: 2017/06/09 16:12:47 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_pow(unsigned int nb, int power)
{
	if (power == 0)
		return (1);
	return (nb * ft_pow(nb, power - 1));
}
