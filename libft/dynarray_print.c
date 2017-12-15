/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vvoid_print_da.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:27:32 by rporcon           #+#    #+#             */
/*   Updated: 2017/05/22 14:48:31 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dynarray_print(t_dyn_array array)
{
	size_t	i;

	i = 0;
	while (i < array.size)
	{
		ft_printf("%zu: %p \n", i, array.elems[i]);
		i++;
	}
}
