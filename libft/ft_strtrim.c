/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:39:08 by rporcon           #+#    #+#             */
/*   Updated: 2017/02/13 16:05:31 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_blank_size(const char *s, int *first_char_save)
{
	int		blank_size;
	int		i;

	i = 0;
	blank_size = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		blank_size++;
		i++;
	}
	*first_char_save = blank_size;
	if (s[i] == '\0')
		return (blank_size);
	while (s[i] != '\0')
		i++;
	i = i - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i >= 0)
	{
		blank_size++;
		i--;
	}
	return (blank_size);
}

char		*ft_strtrim(char const *s)
{
	char	*str_allocate;
	int		blank_size;
	int		str_size;
	int		first_char_add;
	int		i;

	if (s == NULL)
		return (NULL);
	blank_size = ft_blank_size(s, &first_char_add);
	str_size = ft_strlen(s) - blank_size;
	i = 0;
	if ((str_allocate = (char *)malloc(sizeof(char) * (str_size + 1))) == NULL)
		return (NULL);
	while (i < str_size)
	{
		str_allocate[i] = s[first_char_add];
		i++;
		first_char_add++;
	}
	str_allocate[i] = '\0';
	if (i == str_size)
		return (str_allocate);
	return (NULL);
}
