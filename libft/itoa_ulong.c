/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ulong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:21:49 by rporcon           #+#    #+#             */
/*   Updated: 2017/05/17 15:40:19 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*itoa_ulong(unsigned long n)
{
	size_t	i;
	char	*str;

	i = ulong_size(n) - 1;
	if ((str = ft_strnew((ulong_size(n + 1)))) == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
	return (str);
}
