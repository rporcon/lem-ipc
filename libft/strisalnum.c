/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strisalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:15:44 by rporcon           #+#    #+#             */
/*   Updated: 2017/12/11 12:30:27 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		strisalnum(char *str)
{
	size_t	i;
	int		isalnum;

	i = 0;
	isalnum = 1;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == 0)
		{
			isalnum = 0;
			break ;
		}
		i++;
	}
	return (isalnum);
}
