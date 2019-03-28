/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:45:51 by auverneu          #+#    #+#             */
/*   Updated: 2018/06/24 17:00:02 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_error_ls(int err, char *str)
{
	if (err == ILL_OPT)
		printf("%s%c\n%s", "ft_ls: illegal option -- ", str[0], "usage: ft_ls [-1aAcCdflrRtuUs] [file ...]\n");
	else if (err == ALLOC_F)
		printf("test");
	return (-1);
}

int			ft_opts_ls(int ac, char **av, int *flags)
{
	char	*opts;
	char	*ret;
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (i <= ac)
	{
		if (av[i][0] == '-')
		{
			if (av[i][1] == '-')
				break ;
			while (av[i][j])
			{
				if ((ret = ft_strchr(opts, av[i][j])))
					*flags |= (int)1U << (ret - LS_OPTS);
				else
					ft_error_ls(ILL_OPT, &(av[i][j]));
				j++;
			}
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
	}
	return (i);
}

int		ft_cmpstring(const void *a, const void *b)
{
	return (ft_strcmp(*(char * const *)a, *(char * const *)b));
}

int		main(int ac, char **av)
{
	int				*flags;
	int				i;
	char			**paths;

	i = 1;
	flags = malloc(sizeof(int));
	*flags = 0;
	paths = NULL;
	//ioctl(0, TIOCGWINSZ, &sz);
	if (ac > 1)
	{
		i = ft_opts_ls(ac, av, flags);
		if (i == ac)
			paths[0] = ft_strdup(".");
			// if (!ppaths[0])
			// 	return (ERROR);
		else
			paths = av + i;
	}
	else
	{
		paths = (char **)malloc(sizeof(char *));
		// if (!paths)
		// 	return (ERROR);
		paths[0] = ft_strdup(".");
		// if (!ppaths[0])
		// 	return (ERROR);
	}
	printf("{%s}\n", paths[0]);
	//ft_qsort(&av[i], ac - i, sizeof(char *), ft_cmpstring);
	test(*flags, paths, 0);
	free(flags);
	return (0);
}
