/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstrchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 17:25:48 by rporcon           #+#    #+#             */
/*   Updated: 2017/09/04 18:14:15 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*memmemchr(const char *s1, const char *s2, size_t s1len)
{
	size_t	i;
	size_t	j;
	size_t	s2len;

	i = 0;
	s2len = ft_strlen(s2);
	while (i < s1len)
	{
		j = 0;
		while (s2[j] == s1[i + j])
			j++;
		if (j == s2len)
			return ((unsigned char *)s1 + i);
		i++;
	}
	return (NULL);
}
