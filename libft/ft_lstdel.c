/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 11:10:10 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/29 11:35:40 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*tmp_list;

	if (alst && del)
	{
		list = *alst;
		while (list)
		{
			tmp_list = list->next;
			del(list->content, list->content_size);
			free(list);
			list = tmp_list;
		}
		*alst = NULL;
	}
}
