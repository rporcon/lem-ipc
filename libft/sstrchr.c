/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:16:06 by rporcon           #+#    #+#             */
/*   Updated: 2017/12/11 12:28:53 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	sstr must behave like strchr
*/

unsigned char	sstrchr(char **sstr, char *chr)
{
	size_t	i;

	if (sstr == NULL)
		return (0);
	i = 0;
	while (sstr[i] != NULL)
	{
		if (ft_strcmp(sstr[i], chr) == 0)
			return (1);
		i++;
	}
	return (0);
}
