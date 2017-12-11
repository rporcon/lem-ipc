/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:37:42 by rporcon           #+#    #+#             */
/*   Updated: 2017/02/13 16:38:23 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ll_new(t_llist **elem, void *content)
{
	*elem = malloc(sizeof(t_llist));
	(*elem)->content = content;
	(*elem)->next = NULL;
}
