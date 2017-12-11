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

void	ft_vvoid_da_add_elem(t_vvoid_da *vvoid_da, void *new_elem)
{
	void	**vvoid_da_tmp;
	size_t	i;

	vvoid_da_tmp = NULL;
	i = 0;
	if (vvoid_da->size == vvoid_da->len)
	{
		vvoid_da_tmp = malloc(sizeof(void *) * (vvoid_da->size * 2));
		while (i < vvoid_da->size)
		{
			vvoid_da_tmp[i] = vvoid_da->elems[i];
			i++;
		}
		free(vvoid_da->elems);
		vvoid_da->elems = vvoid_da_tmp;
		vvoid_da->len = vvoid_da->size * 2;
	}
	vvoid_da->elems[vvoid_da->size] = new_elem;
	vvoid_da->size++;
}
