/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarr_includes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 10:35:13 by rporcon           #+#    #+#             */
/*   Updated: 2017/05/29 19:23:38 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intarr_includes(int *arr, int arr_size, int tofind)
{
	int		i;

	i = 0;
	while (i < arr_size)
	{
		if (arr[i] == tofind)
			return (1);
		i++;
	}
	return (0);
}
