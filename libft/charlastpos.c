/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charlastpos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 15:07:17 by rporcon           #+#    #+#             */
/*   Updated: 2017/08/18 15:24:16 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	charlastpos(char *s, char c)
{
	size_t	i;
	size_t	last_occur;

	i = 0;
	last_occur = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			last_occur = i;
		i++;
	}
	return (last_occur);
}
