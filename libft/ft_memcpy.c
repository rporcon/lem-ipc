/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:35:35 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/25 16:50:10 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t			i;
	unsigned char	*uc_dst;
	unsigned char	*uc_src;

	i = 0;
	uc_dst = dst;
	uc_src = src;
	while (i < n)
	{
		uc_dst[i] = uc_src[i];
		i++;
	}
	return (dst);
}
