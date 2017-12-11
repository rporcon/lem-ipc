/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:15:13 by rporcon           #+#    #+#             */
/*   Updated: 2017/06/09 16:18:29 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rev_words(char **sstr, size_t len)
{
	size_t	i;
	size_t	mid_str;

	if (sstr == NULL || len <= 1)
		return ;
	i = 0;
	mid_str = len / 2;
	while (i < mid_str && len-- > 0)
	{
		ft_swap_str(&sstr[i], &sstr[len]);
		i++;
	}
}
