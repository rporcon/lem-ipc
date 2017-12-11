/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:01:22 by rporcon           #+#    #+#             */
/*   Updated: 2017/06/09 16:03:49 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_str(char **str1, char **str2)
{
	char	*tmp;

	if (str1 == NULL || str2 == NULL)
		return ;
	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}
