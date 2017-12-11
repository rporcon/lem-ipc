/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strreplace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:41:37 by rporcon           #+#    #+#             */
/*   Updated: 2017/09/04 18:15:47 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	getreplen(char *str, char *torep, char *rep)
{
	size_t	replen;
	size_t	toreplen;
	size_t	i;

	replen = 0;
	toreplen = ft_strlen(torep);
	i = 0;
	if (toreplen != ft_strlen(rep))
	{
		while (str[i] != '\0')
		{
			if (ft_memcmp(str + i, torep, toreplen) == 0)
			{
				replen = toreplen < ft_strlen(rep) ? replen + toreplen :
					toreplen - ft_strlen(rep);
				i += toreplen;
			}
			i++;
		}
	}
	if (toreplen > ft_strlen(rep))
		replen = -replen;
	return (replen);
}

char	*strreplace(char *str, char *torep, char *rep)
{
	char	*newstr;
	char	*newstr_tmp;
	char	*toreppos;
	char	*strend;
	long	str_len;

	if (torep == NULL || rep == NULL || str == NULL)
		return (str);
	str_len = ft_strlen(str);
	newstr = malloc((sizeof(char) * getreplen(str, torep, rep)) + str_len + 1);
	strend = str + str_len;
	newstr_tmp = newstr;
	while ((toreppos = ft_strstr(str, torep)) != NULL)
	{
		ft_memcpy(newstr_tmp, str, toreppos - str);
		ft_memcpy(newstr_tmp + (toreppos - str), rep, ft_strlen(rep));
		newstr_tmp = newstr_tmp + (toreppos - str) + ft_strlen(rep);
		str = str + (toreppos - str) + ft_strlen(torep);
	}
	ft_memcpy(newstr_tmp, str, strend - str);
	newstr_tmp[strend - str] = '\0';
	return (newstr);
}
