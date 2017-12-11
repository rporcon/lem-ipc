/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_leading_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:07:02 by rporcon           #+#    #+#             */
/*   Updated: 2017/05/22 17:13:34 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_leading_char_before(char *str, char c, size_t len)
{
	size_t	i;
	size_t	str_offset;
	char	*new_str;

	if (ft_strlen(str) >= len)
		return (str);
	i = 0;
	str_offset = len - ft_strlen(str);
	new_str = ft_strnew(len + 1);
	ft_strcpy(new_str + str_offset, str);
	while (i < str_offset)
	{
		new_str[i] = c;
		i++;
	}
	free(str);
	return (new_str);
}
