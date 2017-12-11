/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:11:33 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/30 11:15:42 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		str_equal;

	str_equal = -1;
	if (s1 && s2)
	{
		str_equal = ft_strcmp(s1, s2);
		if (str_equal == 0)
			return (1);
	}
	return (0);
}
