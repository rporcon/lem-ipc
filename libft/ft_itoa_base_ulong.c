/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ulong.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:37:11 by rporcon           #+#    #+#             */
/*   Updated: 2017/05/18 15:47:26 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*init_ft_itoa_base_ulong(int base, unsigned long *num,
			int *num_size, char *strnum)
{
	unsigned long	tmp_num;

	if (base <= 0 || base > 16)
		return (NULL);
	if (*num == 0)
	{
		strnum = malloc(sizeof(char) * 2);
		ft_strcpy(strnum, "0\0");
		return (strnum);
	}
	tmp_num = *num;
	while ((tmp_num /= base) > 0)
		(*num_size)++;
	strnum = malloc((sizeof(char) * *num_size) + 2);
	strnum[*num_size + 1] = '\0';
	return (strnum);
}

char	*ft_itoa_base_ulong(unsigned long num, int base)
{
	unsigned char	c;
	short int		mod;
	char			*strnum;
	int				num_size;

	strnum = NULL;
	num_size = 0;
	strnum = init_ft_itoa_base_ulong(base, &num, &num_size, strnum);
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
