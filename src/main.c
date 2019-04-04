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

int			ft_opts_ls(int ac, char **av, t_structls *ls)
{
	char	*ret;
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if (av[i][1] == '-')
				return (i);
			while (av[i][j])
			{
				if ((ret = ft_strchr(LS_OPTS, av[i][j])))
					ls->flags |= (int)1U << (ret - LS_OPTS);
				else
					ft_error_ls(ILL_OPT, &(av[i][j]));
				j++;
		
			}
		}
		else
			return (1);
		if (av[i + 1])
		{
			i++;
			j = 1;
			if (av[i][0] != '-')
				return (i);
		}
		else
			break;
	}
	return (i);
}

int		ft_cmpstring(const void *a, const void *b)
{
	return (ft_strcmp(a, b));
}

int		main(int ac, char **av)
{
	t_structls		ls;
	int				i;
	int				j;

	ls.flags = 0;
	ls.paths = NULL;
	//ioctl(0, TIOCGWINSZ, &sz);

	i = 1;
	j = 0;
	ls.ex = ft_strdup(av[0]);
	i = ft_opts_ls(ac, av, &ls);
	printf("{Hello %d/%d}\n", i, ac);
	if (i == ac)
	{
		ls.paths = malloc(sizeof(char *));
		ls.paths[0] = ft_strdup(".");
	}
	else
	{
		ls.paths = malloc(sizeof(char *) * (ac - i));
		while (i++ < ac)
			ls.paths[j++] = ft_strdup(av[i]);
	}
	
	//paths = (char **)malloc(sizeof(char *) * ((ac - i > 1) ? ac - i : 1));
	// if (!paths)
	// 	return (ERROR);
	if (ft_strcmp(ls.paths[0], ".") != 0)
	{
		qsort(ls.paths, ac - (i > 0 ? i : 1), sizeof(char *), ft_cmpstring);
	}
	test(ls.flags, ls.paths, 0);
	return (0);
}