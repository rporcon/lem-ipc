/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vvoid_da_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:13:56 by rporcon           #+#    #+#             */
/*   Updated: 2017/05/27 17:17:46 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vvoid_da_init(t_vvoid_da *vvoid_da, size_t size, size_t len)
{
	vvoid_da->size = size;
	vvoid_da->len = len;
	vvoid_da->elems = malloc(sizeof(void *) * len);
}
