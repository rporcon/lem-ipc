/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:54:55 by rporcon           #+#    #+#             */
/*   Updated: 2017/12/11 13:54:21 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*c_src;
	unsigned char	*c_dst;

	i = 0;
	c_src = (unsigned char *)src;
	c_dst = (unsigned char *)dst;
	/* if (dst < (src + len) && src < dst) */
	if (dst > src)
	{
		ft_printf("aa\n");
		while (i < len)
		{
			c_dst[len - 1] = c_src[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			c_dst[i] = c_src[i];
			i++;
		}
	}
	return (dst);
}
