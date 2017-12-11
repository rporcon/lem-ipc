/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_byte.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:54:22 by rporcon           #+#    #+#             */
/*   Updated: 2017/03/17 15:21:28 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_hexnum_size(unsigned char *hex_size, unsigned char dec_byte)
{
	while (dec_byte > 0)
	{
		(*hex_size)++;
		dec_byte /= 16;
	}
}

void	ft_putaddr_byte(unsigned char dec_byte)
{
	unsigned char			hex_size;
	unsigned char			hex_num[3];

	hex_size = 0;
	get_hexnum_size(&hex_size, dec_byte);
	if (hex_size == 0)
		ft_putstr("00");
	else if (hex_size == 1)
		ft_putchar('0');
	hex_num[hex_size] = '\0';
	while (dec_byte > 0)
	{
		if ((dec_byte % 16) < 10)
			hex_num[hex_size - 1] = (unsigned char)((dec_byte % 16) + 48);
		else
			hex_num[hex_size - 1] = (unsigned char)((dec_byte % 16) + 87);
		hex_size--;
		dec_byte /= 16;
	}
	ft_putstr((const char*)hex_num);
}
