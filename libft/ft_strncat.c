/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:28:55 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/24 19:31:43 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		s1_size;
	size_t	i;

	s1_size = 0;
	i = 0;
	while (s1[s1_size] != '\0')
		s1_size++;
	while (s2[i] != '\0' && i < n)
	{
		s1[s1_size] = s2[i];
		s1_size++;
		i++;
	}
	s1[s1_size] = '\0';
	return (s1);
}
