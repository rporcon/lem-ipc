/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:06:55 by rporcon           #+#    #+#             */
/*   Updated: 2017/06/02 16:49:37 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_max_fd(size_t n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_max(n / 10);
		ft_putnbr_max(n % 10);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
