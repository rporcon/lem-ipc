/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_prepend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:33:53 by rporcon           #+#    #+#             */
/*   Updated: 2017/02/13 16:34:28 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ll_prepend(t_llist **ll, void *content)
{
	t_llist *elem;
	t_llist *tmp_list;

	tmp_list = *ll;
	ft_ll_new(&elem, content);
	*ll = elem;
	(*ll)->next = tmp_list;
}
