/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint16_swap_bits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:04:49 by rporcon           #+#    #+#             */
/*   Updated: 2017/05/31 15:11:43 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned short	ft_swap_uint16b(unsigned short byte)
{
	unsigned short	swapped_nb;

	swapped_nb = (byte >> 8) | (byte << 8);
	return (swapped_nb);
}
