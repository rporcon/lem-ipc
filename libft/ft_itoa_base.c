/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:41:45 by rporcon           #+#    #+#             */
/*   Updated: 2017/06/09 16:12:10 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*init_ft_itoa_base(int base, int *num, int *num_size, char *strnum)
{
	int				tmp_num;
	int				negative;

	negative = 0;
	if (base <= 0 || base > 16)
		return (NULL);
	if (*num == -2147483648 && base == 10)
		return ("-2147483648");
	if (*num == 0)
	{
		strnum = malloc(sizeof(char) * 2);
		ft_strcpy(strnum, "0\0");
		return (strnum);
	}
	if (*num < 0 && base == 10 && (negative = 1) && ((*num_size)++))
		*num *= -1;
	tmp_num = *num;
	while ((tmp_num /= base) > 0)
		(*num_size)++;
	strnum = malloc((sizeof(char) * *num_size) + 2);
	strnum[*num_size + 1] = '\0';
	negative == 1 ? strnum[0] = '-' : (void)0;
	return (strnum);
}

char	*ft_itoa_base(int num, int base)
{
	unsigned char	c;
	short int		mod;
	char			*strnum;
	int				num_size;

	strnum = NULL;
	num_size = 0;
	strnum = init_ft_itoa_base(base, &num, &num_size, strnum);
	while (num > 0)
	{
		mod = num % base;
		if (mod < 10)
			c = (unsigned char)mod + 48;
		else
			c = (unsigned char)mod + 87;
		strnum[num_size--] = c;
		num /= base;
	}
	return (strnum);
}
