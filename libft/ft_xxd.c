/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xxd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:40:49 by rporcon           #+#    #+#             */
/*   Updated: 2017/05/29 12:41:11 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_xxd(void *mem, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return ;
	while (++i <= size)
	{
		ft_putaddr_byte(((unsigned char*)mem)[i - 1]);
		if (i % 16 == 0)
		{
			ft_putstr(" \n");
			if (i == size)
				return ;
		}
		if (i != 16)
			ft_putchar(' ');
	}
	ft_putchar('\n');
	return ;
}
