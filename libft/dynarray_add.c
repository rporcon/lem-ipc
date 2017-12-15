/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vvoid_da_add_elem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:24:54 by rporcon           #+#    #+#             */
/*   Updated: 2017/05/27 18:17:25 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	dynarray_add(t_dyn_array *array, void *new_elem)
{
	void	**array_tmp;
	size_t	i;

	array_tmp = NULL;
	i = 0;
	if (array->size == array->len)
	{
		array_tmp = malloc(sizeof(void *) * (array->size * 2));
		while (i < array->size)
		{
			array_tmp[i] = array->elems[i];
			i++;
		}
		free(array->elems);
		array->elems = array_tmp;
		array->len = array->size * 2;
	}
	array->elems[array->size] = new_elem;
	array->size++;
}
