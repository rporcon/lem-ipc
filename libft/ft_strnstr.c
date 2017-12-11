/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:16:03 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/29 17:13:13 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	int		size;

	i = 0;
	size = 0;
	while (s2[size])
		size++;
	if (size == 0)
		return ((char *)s1);
	while (i < n && s1[i] != '\0')
	{
		j = 0;
		while ((s2[j] == s1[i + j]) && (i + j < n) && (s2[j] != '\0'))
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
