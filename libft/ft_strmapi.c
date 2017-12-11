/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:57:07 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/26 14:11:55 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			str_allocate[i] = f(i, s[i]);
			i++;
		}
		str_allocate[i] = '\0';
		return (str_allocate);
	}
	return (NULL);
}
