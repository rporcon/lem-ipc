/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:14:47 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/27 16:06:10 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	str_size;

	str_size = 0;
	if (str == NULL)
		return (str_size);
	while (str[str_size] != '\0')
		str_size++;
	return (str_size);
}
