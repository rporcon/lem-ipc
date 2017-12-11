/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 17:48:37 by rporcon           #+#    #+#             */
/*   Updated: 2017/08/29 17:49:03 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memsub(char *s, unsigned int start, size_t len)
{
	char		*mem;
	size_t		i;

	i = 0;
	if (s)
	{
		if ((mem = (char *)malloc(sizeof(char) * len)) == NULL)
			return (NULL);
		while (i < len)
		{
			mem[i] = s[start];
			i++;
			start++;
		}
		return (mem);
	}
	return (NULL);
}
