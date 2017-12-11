/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strisalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:15:34 by rporcon           #+#    #+#             */
/*   Updated: 2017/12/11 12:41:59 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		strisalpha(char *str)
{
	size_t	i;
	int		isalpha;

	i = 0;
	isalpha = 1;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) == 0)
		{
			isalpha = 0;
			break ;
		}
		i++;
	}
	return (isalpha);
}
