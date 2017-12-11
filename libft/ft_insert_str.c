/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:48:03 by rporcon           #+#    #+#             */
/*   Updated: 2017/08/12 15:48:04 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert_str(char *src, char *dest, unsigned int pos)
{
	char	*new_str;
	char	*before;
	char	*after;
	size_t	str_len;

	if (!src)
		return (NULL);
	else if (!dest || pos >= ft_strlen(src))
		return (src);
	str_len = ft_strlen(src) + ft_strlen(dest);
	before = ft_strsub(src, 0, pos);
	after = ft_strsub(src, pos, str_len);
	new_str = ft_strnew(str_len);
	ft_strcat(new_str, before);
	ft_strcat(new_str, dest);
	ft_strcat(new_str, after);
	free(before);
	free(after);
	return (new_str);
}
