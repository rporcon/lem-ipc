/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:42:15 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/30 11:11:25 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str_allocate;
	size_t		i;

	i = 0;
	if (s)
	{
		if ((str_allocate = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		while (i < len && s[start] != '\0')
		{
			str_allocate[i] = s[start];
			i++;
			start++;
		}
		str_allocate[i] = '\0';
		return (str_allocate);
	}
	return (NULL);
}
