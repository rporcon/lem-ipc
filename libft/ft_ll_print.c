/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:35:01 by rporcon           #+#    #+#             */
/*   Updated: 2017/02/13 16:35:16 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ll_print(t_llist *ll)
{
	while (ll)
	{
		ft_putstr(ll->content);
		ft_putchar('\n');
		ll = ll->next;
	}
}
