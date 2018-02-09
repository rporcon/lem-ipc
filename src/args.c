/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:54:26 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/09 18:34:16 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	print_help(void)
{
	printf("Usage: ./lemipc [team id] [options]\n"
			"\t-h     print this help screen\n"
			"\t-e     erase all ressources\n");
	exit(0);
}

void	req_args(int ac, char **av)
{
	int		reqarg_nb;
	int		i;

	reqarg_nb = 0;
	i = 1;
	while (i < ac)
	{
		if (reqarg_nb == 0)
			g_data.team_id = atoi_max(av[i]);
		else if (reqarg_nb > 1)
			err_exit("too many args", 1);
		reqarg_nb++;
		i++;
	}
	if (reqarg_nb != 1)
		print_help();
	if (g_data.team_id == 0 || g_data.team_id >= 100)
		err_exit("Invalid team_id name (maybe too long)", 1);
}

void	get_args(int ac, char **av)
{
	char	c;

	while ((c = getopt(ac, av, "he")) != -1)
	{
		if (c == 'h')
			print_help();
		else if (c == 'e')
		{
			g_data.ressources_erase_opt = 1;
			ressources_erase();
		}
		else if (c == '?')
		{
			if (ft_isprint(optopt))
				fprintf(stderr, "Unknown option '-%c'.\n", optopt);
			else
				fprintf(stderr, "Unknown option character '%c'.\n",
					optopt);
			exit(1);
		}
	}
	req_args(ac, av);
}
