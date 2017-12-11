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

void	ft_print_vvoid_da(t_vvoid_da vvoid_da)
{
	size_t	i;

	i = 0;
	while (i < vvoid_da.size)
	{
		ft_printf("%zu: %p \n", i, vvoid_da.elems[i]);
		i++;
	}
}
