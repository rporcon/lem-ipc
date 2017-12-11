/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 18:54:03 by rporcon           #+#    #+#             */
/*   Updated: 2017/08/19 18:54:06 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_basename(char *path)
{
	char	**split;
	char	*basename;
	int		i;

	i = 0;
	if ((split = ft_strsplit(path, '/')) == NULL)
		return (ft_strdup(path));
	while (split[i + 1] != NULL)
		i++;
	basename = ft_strdup(split[i]);
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (basename);
}
