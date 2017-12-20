#include "lemipc.h"

void		print_help()
{
	printf("Usage: ./lemipc [team id]\n");
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
			g_opt.team_id = atoi_max(av[i]);
		else if (reqarg_nb > 1)
			err_exit("too many args", 1);
		reqarg_nb++;
		i++;
	}
	if (reqarg_nb != 1)
		print_help();
}

void	get_args(int ac, char **av)
{
	char	c;

	while ((c = getopt (ac, av, "6hrke:g")) != -1) {
		switch (c)
		{
			case 'h':
				print_help();
				break ;
			case '?':
				if (ft_isprint (optopt))
					fprintf(stderr, "Unknown option '-%c'.\n", optopt);
				else
					fprintf(stderr, "Unknown option character '%c'.\n",
						optopt);
				exit(1);
			default:
				break ;
		}
	}
	req_args(ac, av);
}
