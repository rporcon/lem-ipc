/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:21:17 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/26 14:35:02 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		str_equal;

	str_equal = -1;
	if (s1 && s2)
	{
		str_equal = ft_strncmp(s1, s2, n);
		if (str_equal == 0)
			return (1);
	}
	return (0);
}
