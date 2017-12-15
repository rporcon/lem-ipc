/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:45:38 by rporcon           #+#    #+#             */
/*   Updated: 2017/08/19 18:40:27 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*syscmd_tostr(char *cmd)
{
	FILE 	*fs;
	char 	*str;

	str = malloc(BUF_SIZE);
	if ((fs = popen(cmd, "r")) == NULL)
		perr_exit("popen");
	fread(str, BUF_SIZE, 1, fs);
	return (str);
}
