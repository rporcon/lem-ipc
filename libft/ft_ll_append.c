/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:35:40 by rporcon           #+#    #+#             */
/*   Updated: 2017/02/13 16:37:24 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ll_append(t_llist **ll, void *content)
{
	t_llist *elem;
	t_llist *tmp_list;

	ft_ll_new(&elem, content);
	if (!*ll)
		*ll = elem;
	else
	{
		tmp_list = *ll;
		while (tmp_list->next)
			tmp_list = tmp_list->next;
		tmp_list->next = elem;
	}
}
