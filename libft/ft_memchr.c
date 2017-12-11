/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:21:26 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/30 11:26:15 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*str;
	unsigned char			uc;
	size_t					i;

	i = 0;
	uc = (unsigned char)c;
	str = s;
	while (i < n)
	{
		if (str[i] == uc)
			return ((void*)s + i);
		i++;
	}
	return (NULL);
}
