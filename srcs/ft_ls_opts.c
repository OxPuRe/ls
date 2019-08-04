/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_opts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:27:13 by auverneu          #+#    #+#             */
/*   Updated: 2019/08/04 11:38:20 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_recup_flag(char *av, t_ls *ls)
{
	char		*chr;
	int			rot;

	if (ft_strequ(av, LS_H_OPT))
		ls_exit(LS_E_HELP, NULL, ls);
	av++;
	while (*av)
	{
		chr = ft_strchr(LS_OPTS, *av);
		if (chr == NULL)
			ls_exit(LS_E_ARG, av, ls);
		rot = (int)(chr - LS_OPTS);
		if (*av == '1' || *av == 'l')
			ls->flag &= ~(LS_F_LONG | LS_F_LINE);
		else if (*av == 'u' || *av == 'U' || *av == 'c')
			ls->flag &= ~(LS_F_STATUS | LS_F_ACCESS | LS_F_CREATION);
		ls->flag |= 1U << rot;
		av++;
	}
}

static void		ls_check_av(int i, int ac, char **av, t_ls *ls)
{
	struct stat	err;

	while (i < ac)
	{
		if (!ft_strcmp(av[i], ""))
		{
			lstat(av[i], &err);
			ls_exit(LS_E_STD_EXIT, "fts_open", ls);
		}
		i++;
	}
}

void			ls_opts(int ac, char **av, t_ls *ls)
{
	int			i;

	i = 1;
	while (i < ac && *(av[i]) == '-' && ft_strlen(av[i]) != 1 &&
		!ft_strequ(av[i], "--"))
	{
		ls_recup_flag(av[i], ls);
		i++;
	}
	if (ft_strequ(av[i], "--"))
		i++;
	if (ls->flag & LS_F_NOSORT)
		ls->flag |= LS_F_ALL;
	ls_check_av(i, ac, av, ls);
	ls->nbe = (ac - i);
	ls_recup_arg(ls, av + i);
}
