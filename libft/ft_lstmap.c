/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 11:59:58 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/30 13:12:12 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*new_list_begin;

	if (lst == NULL)
		return (NULL);
	if ((new_list = ft_lstnew(lst->content, lst->content_size)) == NULL)
		return (NULL);
	new_list = f(lst);
	new_list_begin = new_list;
	while (lst->next)
	{
		if ((new_list->next = ft_lstnew(lst->content, lst->content_size))
			== NULL)
			return (NULL);
		new_list->next = f(lst->next);
		new_list = new_list->next;
		lst = lst->next;
	}
	return (new_list_begin);
}
