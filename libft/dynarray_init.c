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

void	dynarray_init(t_dyn_array *array, size_t size, size_t len)
{
	array->size = size;
	array->len = len;
	array->elems = malloc(sizeof(void *) * len);
}
