/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulong_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:44:50 by rporcon           #+#    #+#             */
/*   Updated: 2017/08/12 15:45:00 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ulong_size(size_t number)
{
	size_t	size;

	size = 0;
	while (number)
	{
		size++;
		number /= 10;
	}
	return (size);
}
