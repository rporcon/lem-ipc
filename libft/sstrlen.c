/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:15:02 by rporcon           #+#    #+#             */
/*   Updated: 2017/06/09 16:15:04 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	sstrlen(char **sstr)
{
	size_t	i;

	i = 0;
	if (sstr == NULL)
		return (0);
	while (sstr[i] != NULL)
		i++;
	return (i);
}
