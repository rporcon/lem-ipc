/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:57:23 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/30 15:41:11 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str_allocate;
	size_t	i;
	size_t	max_size;

	i = 0;
	max_size = (size_t)-1;
	if (size == max_size)
	{
		if ((str_allocate = (char *)malloc(sizeof(char) * (size))) == NULL)
			return (NULL);
	}
	else if ((str_allocate = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (i < size)
	{
		str_allocate[i] = '\0';
		i++;
	}
	str_allocate[i] = '\0';
	return (str_allocate);
}
