/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_opts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:27:13 by auverneu          #+#    #+#             */
/*   Updated: 2019/05/17 19:58:46 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_recup_arg(t_stls *ls, char **av, int ac, int i)
{
	int			j;
	struct stat	*stat;

	j = 0;
	stat = NULL;
	ls->nbe = (ac - i) ? (ac - i) : 1;
	ls->arg = malloc(sizeof(t_arg) * ls->nbe);
	// TODO : err malloc
	// if (!ls->elem)
	// 	return (ERROR);
	if ((ac - i) != 0)
	{
		while (i < ac)
		{
			ls->arg[j].name = ft_strdup(av[i]);
			lstat(av[i], stat);
			ls->arg[j].type = (stat->st_mode & S_IFDIR) ? 'd' : '-';
			ls->arg[j].right = (stat->st_mode & S_IRUSR) ? 'r' : '-';
			ls->arg[j].size = stat->st_size;
			i++;
			j++;
		}
	}
	else
		ls->arg[0].name = ft_strdup(".");
}

void			ft_recup_flag(t_stls *ls, char **av, int i, int j)
{
	char		*ret;

	if (av[i][1] == '-')
		return ;
	while (av[i][j])
	{
		if ((ret = ft_strchr(LS_OPTS, av[i][j])))
			ls->flag |= (int)1U << (ret - LS_OPTS);
		else
			ft_ls_error(ILL_OPT, &(av[i][j]));
		j++;
	}
}

void			ft_ls_opts(int ac, char **av, t_stls *ls)
{
	int			i;
	int			j;

	i = 1;
	j = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
			ft_recup_flag(ls, av, i, j);
		else
			break ;
		if (av[i++ + 1])
			j = 1;
		else
			break ;
	}
printf("%d\n", i);
	ft_recup_arg(ls, av, ac, i);
	//if (!(ls.flag & (F_F | F_UU)))
	//	ft_ls_sort(&ls, 0);
}
