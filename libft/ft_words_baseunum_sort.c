/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words_baseunum_sort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:12:59 by rporcon           #+#    #+#             */
/*   Updated: 2017/06/09 16:15:47 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_words_baseunum_sort(char **sstr, size_t len, int base)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi_base_max(sstr[i], base) >
					ft_atoi_base_max(sstr[j], base))
				ft_swap_str(&sstr[i], &sstr[j]);
			j++;
		}
		i++;
	}
}
