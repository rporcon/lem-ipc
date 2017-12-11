/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint32_swap_bits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:08:24 by rporcon           #+#    #+#             */
/*   Updated: 2017/05/31 15:12:31 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_swap_uint32b(unsigned int num)
{
	unsigned int	swapped_nb;

	swapped_nb = ((num >> 24) & 0xff) |
	((num << 8) & 0xff0000) |
	((num >> 8) & 0xff00) |
	((num << 24) & 0xff000000);
	return (swapped_nb);
}
