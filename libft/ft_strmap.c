/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:14:23 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/26 14:12:01 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str_allocate;
	int		str_size;
	int		i;

	if (s && f)
	{
		str_size = ft_strlen(s);
		i = 0;
		if ((str_allocate = (char *)malloc(sizeof(char) *
			(str_size + 1))) == NULL)
			return (NULL);
		while (i < str_size)
		{
			str_allocate[i] = f(s[i]);
			i++;
		}
		str_allocate[i] = '\0';
		return (str_allocate);
	}
	return (NULL);
}
