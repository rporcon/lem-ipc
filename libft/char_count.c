/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:38:31 by rporcon           #+#    #+#             */
/*   Updated: 2017/02/13 16:39:18 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_count(char const *s, char c)
{
	int	char_count;

	char_count = 0;
	while (*s)
	{
		if (*s == c)
			char_count++;
		s++;
	}
	return (char_count);
}
