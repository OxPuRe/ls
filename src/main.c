/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:45:51 by auverneu          #+#    #+#             */
/*   Updated: 2018/05/23 17:47:47 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_error_ls(int err, char *str)
{
	if (err == ILL_OPT)
		printf("%s%c\n%s", "ls: illegal option -- ", str[0], "usage: ft_ls [-1aAcCdflrRtuUs] [file ...]\n");
	return (-1);
}

char		*ft_opts_ls(int ac, char **av, int flags)
{
	int		i;
	int		j;
	char	*opts;

	i = 0;
	j = 0;
	flags = 0;
	opts = "-1aAcCdflrRtuUs";
	if (ac == 1 || av[1][0] != '-')
		return (0);
	if (av[1][1] == '-')
		return (ft_error_ls(ILL_OPT, "-"));
	while (++j < ac && av[j] && av[j][0] == '-')
	{
		while (av[j][++i])
		{
			if (ft_strchr(opts, av[j][i]))
				flags |= (int)ft_pow(2, (ft_strchr(opts, av[j][i]) - opts - 1));
			else
				return (ft_error_ls(ILL_OPT, &av[j][i]));
		}
	}
	return (&av[j]);
}

int		main(int ac, char **av)
{
	struct winsize	sz;
	int				*flags;
	char			**arg;

	arg = ft_opts_ls(ac, av, &flags);
	ioctl(0, TIOCGWINSZ, &sz);
	if ((flags & F_L) != 0)
		ft_infolst_ls(flags, arg);
	else
		ft_inforeg_ls(sz.ws_col, flags, arg);
	return (0);
}
