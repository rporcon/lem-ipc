/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstrfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:15:53 by rporcon           #+#    #+#             */
/*   Updated: 2017/12/11 11:15:56 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sstrfree(char **sstr)
{
	int i;

	if (sstr == NULL)
		return ;
	i = 0;
	while (sstr[i])
	{
		free(sstr[i]);
		i++;
	}
	free(sstr);
}
