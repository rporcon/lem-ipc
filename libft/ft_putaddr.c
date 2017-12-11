/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:05:50 by rporcon           #+#    #+#             */
/*   Updated: 2017/03/17 13:00:26 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putaddr(const void *addr)
{
	unsigned char			dec_byte;
	int						hex_addr_len;

	if (addr == NULL)
	{
		ft_putstr("(nil)");
		return ;
	}
	dec_byte = 0;
	hex_addr_len = 5;
	ft_putstr("0x");
	while (hex_addr_len >= 0)
	{
		dec_byte = ((unsigned char*)&addr)[hex_addr_len];
		ft_putaddr_byte(dec_byte);
		hex_addr_len--;
	}
}
