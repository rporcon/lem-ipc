/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:45:44 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/27 13:57:59 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*allocate_s;
	int		s_size;
	int		i;

	s_size = 0;
	i = 0;
	while (s[s_size] != '\0')
		s_size++;
	if ((allocate_s = (char *)malloc(sizeof(*allocate_s) *
		(s_size + 1))) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		allocate_s[i] = s[i];
		i++;
	}
	allocate_s[i] = '\0';
	return (allocate_s);
}
