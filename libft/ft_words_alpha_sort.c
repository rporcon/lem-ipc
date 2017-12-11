/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words_alpha_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:01:53 by rporcon           #+#    #+#             */
/*   Updated: 2017/05/22 19:21:34 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_words_alpha_sort(char **sstr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (sstr == NULL || len <= 1)
		return ;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strcmp(sstr[i], sstr[j]) > 0)
				ft_swap_str(&sstr[i], &sstr[j]);
			j++;
		}
		i++;
	}
}
