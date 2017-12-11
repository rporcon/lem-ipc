/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:49:27 by rporcon           #+#    #+#             */
/*   Updated: 2017/08/12 15:49:29 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert_char(char *str, char c, unsigned int pos)
{
	char	*new_str;
	char	*before;
	char	*after;
	size_t	str_len;

	if (!str)
		return (NULL);
	else if (pos >= ft_strlen(str))
		return (str);
	str_len = ft_strlen(str);
	before = ft_strsub(str, 0, pos);
	after = ft_strsub(str, pos, str_len);
	new_str = ft_strnew(str_len + 1);
	ft_strcat(new_str, before);
	new_str[pos] = c;
	ft_strcat(new_str, after);
	free(before);
	free(after);
	return (new_str);
}
