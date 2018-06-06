/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:45:51 by auverneu          #+#    #+#             */
/*   Updated: 2018/06/06 19:24:11 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_error_ls(int err, char *str)
{
	if (err == ILL_OPT)
		printf("%s%c\n%s", "ls: illegal option -- ", str[0], "usage: ft_ls [-1aAcCdflrRtuUs] [file ...]\n");
	else if (err == ALLOC_F)
		printf("test");
	return (-1);
}

void		ft_opts_ls(int ac, char **av, int *flags)
{
	int		i;
	char	*opts;

	i = 0;
	*flags = 0;
	opts = "-1aAcCdflrRtuUs";
	if (ac == 1)
		*av = ".";
	else
	{
		while (*(++av) && *av[0] == '-')
		{
			while (*av[++i])
			{
				if (ft_strchr(opts, *av[i]))
					*flags |= (int)ft_pow(2, (ft_strchr(opts, *av[i]) - opts - 1));
				else
					ft_error_ls(ILL_OPT, &(*av[i]));
			}
		}
		if (!*flags || (*flags && *av))
			av++;
		else
			*av = ".";
	}
}

int		main(int ac, char **av)
{
	int				*flags;
	int				*prc;
	int				i;

	flags = (int *)malloc(sizeof(int));
	prc = (int *)malloc(sizeof(int));
	//ioctl(0, TIOCGWINSZ, &sz);
	ft_opts_ls(ac, av, flags);
	i = 0;
	ft_putstr(*av);
	while (*av)
	{
		ft_info_ls(*flags, *av, prc);
		free(prc);
		av++;
	}
	free(flags);
	return (0);
}
