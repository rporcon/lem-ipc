/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perr_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 18:23:15 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/05 18:23:16 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		perr_exit(const char *str)
{
	perror(str);
	exit(1);
}
