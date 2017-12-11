/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:58:20 by rporcon           #+#    #+#             */
/*   Updated: 2017/02/13 16:05:11 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**sstr;
	char	*pos;
	int		i;

	i = 0;
	sstr = malloc(sizeof(char*) * (ft_char_count(s, c) + 2));
	if (charpos((char *)s, c) == -1) {
		sstr[0] = ft_strdup(s);
		sstr[1] = NULL;
		return (sstr);
	}
	while (pos != NULL)
	{
		sstr[i] = malloc((sizeof(char) * (pos - s)) + 1);
		sstr[i] = ft_strncpy(sstr[i], s, pos - s);
		sstr[i][pos - s] = '\0';
		s = pos + 1;
		pos = ft_strchr(s, c);
		i++;
	}
	if (ft_strlen(s) != 0)
	{
		sstr[i] = malloc((sizeof(char) * ft_strlen(s)) + 1);
		sstr[i] = ft_strcpy(sstr[i], s);
		i++;
	}
	sstr[i] = NULL;
	return (sstr);
}
