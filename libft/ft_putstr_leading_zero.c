/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_leading_zero.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 14:59:04 by rporcon           #+#    #+#             */
/*   Updated: 2017/05/18 14:56:43 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_leading_zero(char *str, unsigned int nb)
{
	unsigned int	i;

	i = 0;
	while (i < nb - ft_strlen(str))
	{
		ft_putchar('0');
		i++;
	}
	ft_putstr(str);
}
