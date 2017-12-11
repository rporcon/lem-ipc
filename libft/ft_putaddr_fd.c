/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:06:40 by rporcon           #+#    #+#             */
/*   Updated: 2017/03/17 13:00:33 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putaddr_fd(const void *addr, int fd)
{
	unsigned char			dec_byte;
	int						hex_addr_len;

	if (addr == NULL)
	{
		ft_putstr_fd("(nil)", fd);
		return ;
	}
	dec_byte = 0;
	hex_addr_len = 5;
	ft_putstr_fd("0x", fd);
	while (hex_addr_len >= 0)
	{
		dec_byte = ((unsigned char*)&addr)[hex_addr_len];
		ft_putaddr_byte_fd(dec_byte, fd);
		hex_addr_len--;
	}
}
