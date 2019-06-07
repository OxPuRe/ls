/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_opts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:27:13 by auverneu          #+#    #+#             */
/*   Updated: 2019/06/07 07:33:01 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_recup_arg(t_ls *ls, char **av, int ac, int i)
{
	int			j;
	int			l;
	t_var		v;

	v.blk = 0;
	j = 0;
	ls->nbe = (ac - i) ? (ac - i) : 1;
	v.s.s.tmp = ls->nbe;
	ls->arg = malloc(sizeof(t_infols) * ls->nbe);
	// TODO : err malloc
	if ((ac - i) != 0)
	{
		while (i < ac)
		{
			ls->arg[j].name = ft_strdup(av[i]);
			l = ft_strlen(ls->arg[j].name) - 1;
			ls->arg[j].name[l] = (ls->arg[j].name[l] == '/') ?
										'\0' : ls->arg[j].name[l];
			i++;
			j++;
		}
	}
	else
		ls->arg[0].name = ft_strdup(".");
	ft_ls_fill(ls->arg, ls, "./", &v);
}

void			ft_recup_flag(t_ls *ls, char **av, int i, int j)
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

void			ft_ls_opts(int ac, char **av, t_ls *ls)
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
	ft_recup_arg(ls, av, ac, i);
}
