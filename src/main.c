/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:45:51 by auverneu          #+#    #+#             */
/*   Updated: 2018/06/14 18:40:53 by auverneu         ###   ########.fr       */
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

int			ft_opts_ls(char **av, int *flags)
{
	char	*opts;
	int		i;
	int		j;

	i = 1;
	j = 1;
	opts = "-1aAcCdflrRtuUs";
	while (av[i])
	{
		if (av[i][0] == '-')
			while (av[i][j])
			{
				if (ft_strchr(opts, av[i][j]))
					*flags |= (int)ft_pow(2, (ft_strchr(opts, av[i][j]) - opts - 1));
				else
					ft_error_ls(ILL_OPT, &(av[i][j]));
				j++;
			}
		else
			break;
		j = 1;
		if (av[i + 1])
		{
			i++;
			if (av[i][0] != '-')
				break;
		}
		else
		{
			av[i] = "./";
			break;
		}
	}
	return (i);
}

int		main(int ac, char **av)
{
	int				*flags;
	int				i;

	i = 0;
	flags = (int *)malloc(sizeof(int));
	*flags = 0;
	//ioctl(0, TIOCGWINSZ, &sz);
	if (ac != 1)
		i = ft_opts_ls(av, flags);
	else
		av[i] = "./";
	while (av[i])
	{
		ft_info_ls(*flags, av[i]);
		i++;
	}
	free(flags);
	return (0);
}
