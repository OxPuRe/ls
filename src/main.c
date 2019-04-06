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
		if (av[i++ + 1])
		{
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
	return (ft_strcmp(*((char * const *)a), *((char * const *)b)));
}

int		main(int ac, char **av)
{
	t_structls		ls;
	int				i;
	int				j;

	ls.flags = 0;
	ls.paths = NULL;
	//ioctl(0, TIOCGWINSZ, &sz);

	j = 0;
	ls.ex = ft_strdup(av[0]);
	i = ft_opts_ls(ac, av, &ls);
	ls.nb = (ac - i) ? (ac - i) : 1;
	ls.paths = malloc(sizeof(char *) * ls.nb);
	// if (!paths)
	// 	return (ERROR);
//printf("{ %d }\n", i);
	if ((ac - i) != 0)
	{
		while (i < ac)
		{
			ls.paths[j] = ft_strdup(av[i]);
			i++;
			j++;
		}
	}
	else
		ls.paths[0] = ft_strdup(".");
	ft_qsort(ls.paths, ls.nb, sizeof(char *), &ft_cmpstring);
	test(&ls, ls.paths);
	return (0);
}