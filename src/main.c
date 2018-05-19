/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <@student.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:45:51 by                   #+#    #+#             */
/*   Updated: 2018/05/19 19:28:42 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_error_ls(int err, char *str)
{
	if (err == ILL_OPT)
		printf("%s%c\n%s", "ls: illegal option -- ", str[0], "usage: ft_ls [-1aAcCdflrRtuUs] [file ...]\n");
	return (-1);
}

int		ft_opts_ls(int ac, char **av)
{
	int		flags;
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
	return (flags);
}

int		ft_core_ls(int ac, char **av, int flags)
{
	DIR				*rep;
	char			*rep_name;
	struct dirent	*rep_info;
	int				prc_size;

	rep = NULL;
	rep_info = NULL;
	if (ac == 1)
		rep_name = "./";
	else
		rep_name = av[1];
rep_name = "./";
	if (!(rep = opendir(rep_name)))
		exit(1);
	while ((rep_info = readdir(rep)) != NULL)
	{
		if ((flags & F_L) != 0)
			ft_infolst_ls(&prc_size, rep_info->d_name, flags);
		//else
			//ft_info_ls();
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		flags;

	flags = ft_opts_ls(ac, av);
	ft_core_ls(ac, av, flags);
	return (0);
}
