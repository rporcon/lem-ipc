/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:50:20 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/30 11:32:17 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*uc_dst;
	unsigned char	*uc_src;
	unsigned char	uc_c;

	i = 0;
	uc_dst = dst;
	uc_src = src;
	uc_c = c;
	while (i < n)
	{
		uc_dst[i] = uc_src[i];
		if (uc_src[i] == uc_c)
			return (dst + (i + 1));
		i++;
	}
	return (NULL);
}
