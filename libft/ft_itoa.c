/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:38:11 by rporcon           #+#    #+#             */
/*   Updated: 2017/05/17 15:37:59 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_size(int number)
{
	int		size;

	size = 0;
	if (number < 0)
		size++;
	while (number)
	{
		size++;
		number /= 10;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = int_size(n) - 1;
	if ((str = ft_strnew(int_size(n) + 1)) == NULL)
		return (NULL);
	if (n == -2147483648)
		str = ft_strdup("-2147483648");
	else if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
	return (str);
}
