/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:29:37 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/30 14:30:02 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*tmp;

	while (*begin_list != NULL)
	{
		tmp = (*begin_list)->next;
		free(*begin_list);
		*begin_list = tmp;
		*begin_list = (*begin_list)->next;
	}
}
