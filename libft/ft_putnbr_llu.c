/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_llu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:56:10 by rporcon           #+#    #+#             */
/*   Updated: 2017/06/02 17:01:21 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_llu(unsigned long long n)
{
	if (n > 9)
	{
		ft_putnbr_llu(n / 10);
		ft_putnbr_llu(n % 10);
	}
	else
		ft_putchar(n + '0');
}
