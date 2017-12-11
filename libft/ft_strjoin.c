/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:20:19 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/27 14:52:31 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_allocate;
	int		s1_s2_size;

	if (s1 && s2)
	{
		s1_s2_size = ft_strlen(s1) + ft_strlen(s2) + 1;
		if ((str_allocate = ft_strnew(s1_s2_size)) == NULL)
			return (NULL);
		str_allocate = ft_strcat(str_allocate, s1);
		str_allocate = ft_strcat(str_allocate, s2);
		return (str_allocate);
	}
	return (NULL);
}
