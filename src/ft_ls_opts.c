/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_opts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:27:13 by auverneu          #+#    #+#             */
/*   Updated: 2019/04/25 16:48:00 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_infols		*ft_alloc_elem(t_stls *ls, char **av, int ac, int i)
{
	int			j;
	t_infols	*info;

	j = 0;
	ls->nbe = (ac - i) ? (ac - i) : 1;
	info = malloc(sizeof(t_infols) * ls->nbe);
	// TODO : err malloc
	// if (!ls->elem)
	// 	return (ERROR);
	if ((ac - i) != 0)
	{
		while (i < ac)
		{
			info[j].name = ft_strdup(av[i]);
			i++;
			j++;
		}
	}
	else
		info[0].name = ft_strdup(".");
	return (info);
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

t_infols		*ft_ls_opts(int ac, char **av, t_stls *ls)
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
	return (ft_alloc_elem(ls, av, ac, i));
}
