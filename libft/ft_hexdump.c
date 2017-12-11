/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:34:24 by rporcon           #+#    #+#             */
/*   Updated: 2017/05/16 16:48:18 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_str_bytes(void *mem, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 16)
		ft_putstr("  ");
	else
	{
		i = size;
		ft_putchar(' ');
		while (i++ <= 15)
			ft_putstr("   ");
	}
	i = 0;
	while (i < size)
	{
		if (ft_isprint(((unsigned char*)mem)[i]) == 0)
			ft_putchar('.');
		else
			ft_putchar(((unsigned char*)mem)[i]);
		i++;
	}
	ft_putchar('\n');
}

void	ft_hexdump(void *mem, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return ;
	ft_printf("%p:  ", mem);
	while (++i <= size)
	{
		ft_putaddr_byte(((unsigned char*)mem)[i - 1]);
		if (i % 16 == 0)
		{
			print_str_bytes(mem + i - 16, 16);
			if (i == size)
				return ;
			ft_printf("%p: ", mem + i);
		}
		ft_putchar(' ');
	}
	print_str_bytes(mem + (i - 1) - ((i - 1) % 16), (i - 1) % 16);
	return ;
}
