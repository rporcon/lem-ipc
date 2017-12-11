/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:41:36 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/29 18:16:38 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem_allocate;

	if ((mem_allocate = malloc(sizeof(*mem_allocate) * size)) == NULL)
		return (NULL);
	ft_memset(mem_allocate, 0, size);
	return (mem_allocate);
}
