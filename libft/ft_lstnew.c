/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:45:28 by rporcon           #+#    #+#             */
/*   Updated: 2015/11/30 13:12:29 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_element;

	if ((new_element = (t_list *)malloc(sizeof(*new_element))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_element->content = NULL;
		new_element->content_size = 0;
	}
	else
	{
		if ((new_element->content = malloc(sizeof(new_element->content) *
			content_size)) == NULL)
			return (NULL);
		ft_memcpy(new_element->content, (void *)content, content_size);
		new_element->content_size = content_size;
	}
	new_element->next = NULL;
	return (new_element);
}
