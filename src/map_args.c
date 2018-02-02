#include <map_print.h>

void	print_help(void)
{
	printf("Usage: ./map [options]\n"
			"\t-h     print this help\n"
			"\t-k     keep old map\n");
	exit(0);
}

void	get_args(int ac, char **av)
{
	char	c;

	while ((c = getopt(ac, av, "kh")) != -1)
	{
		if (c == 'h')
			print_help();
		else if (c == 'k')
			g_data.keep_map = 1;
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
}
