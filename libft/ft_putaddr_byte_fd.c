/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_byte_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:59:27 by rporcon           #+#    #+#             */
/*   Updated: 2017/03/17 15:21:29 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_hexnum_size_fd(unsigned char *hex_size, unsigned char dec_byte)
{
	while (dec_byte > 0)
	{
		(*hex_size)++;
		dec_byte /= 16;
	}
}

void	ft_putaddr_byte_fd(unsigned char dec_byte, int fd)
{
	unsigned char			hex_size;
	unsigned char			hex_num[3];

	hex_size = 0;
	get_hexnum_size_fd(&hex_size, dec_byte);
	if (hex_size == 0)
		ft_putstr_fd("00", fd);
	else if (hex_size == 1)
		ft_putchar_fd('0', fd);
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
	ft_putstr_fd((const char*)hex_num, fd);
}
