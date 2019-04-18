/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opts_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:27:13 by auverneu          #+#    #+#             */
/*   Updated: 2019/04/18 13:00:28 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void        ft_alloc_elem(t_structls *ls, char **av, int ac, int i)
{
    int     j;

    j = 0;
	ls->nbe = (ac - i) ? (ac - i) : 1;
	ls->elem = malloc(sizeof(char *) * ls->nbe);
	// if (!ls->elem)
	// 	return (ERROR);
     if ((ac - i) != 0)
	{
		while (i < ac)
		{
			ls->elem[j] = ft_strdup(av[i]);
			i++;
			j++;
		}
	}
	else
		ls->elem[0] = ft_strdup(".");
}

void        ft_recup_flag(t_structls *ls, char **av, int i, int j)
{
    char    **ret;

	if (av[i][1] == '-')
		return (i);
	while (av[i][j])
	{
		if ((ret = ft_strchr(LS_OPTS, av[i][j])))
			ls->flag |= (int)1U << (ret - LS_OPTS);
		else
			ft_error_ls(ILL_OPT, &(av[i][j]));
		j++;
	}
}

void		ft_opts_ls(int ac, char **av, t_structls *ls)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
            ft_recup_flag(ls, av, i, j);
		else
			break;
		if (av[i++ + 1])
			j = 1;
		else
			break;
	}
    ft_alloc_elem(ls, av, ac, i);
}