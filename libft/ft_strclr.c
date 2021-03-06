/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:40:03 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/30 13:12:40 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		i;
	int		size;

	i = 0;
	if (s)
	{
		size = ft_strlen(s);
		while (i < size)
		{
			s[i] = '\0';
			i++;
		}
	}
}
