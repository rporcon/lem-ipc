/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strisdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:15:21 by rporcon           #+#    #+#             */
/*   Updated: 2017/12/11 12:41:30 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		strisdigit(char *str)
{
	size_t	i;
	int		isdigit;

	i = 0;
	isdigit = 1;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
		{
			isdigit = 0;
			break ;
		}
		i++;
	}
	return (isdigit);
}
