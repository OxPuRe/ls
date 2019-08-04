/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:45:51 by auverneu          #+#    #+#             */
/*   Updated: 2019/08/04 07:58:48 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		*ls_exit(int mode, void *arg, t_ls *ls)
{
	ls->aff_dir = 1;
	if (mode == LS_E_STD_EXIT || mode == LS_E_STD)
	{
		ft_dprintf(2, "%s: ", ls->ex);
		perror((char *)arg);
		if (mode == LS_E_STD_EXIT)
			exit(1);
	}
	else if (mode == LS_E_ARG)
	{
		ft_dprintf(2, "%s: illegal option -- %c\n"
			"usage: ft_ls [-" LS_OPTS " " LS_H_OPT "] [file ...]\n",
			ls->ex, *(char *)arg);
		exit(1);
	}
	else if (mode == LS_E_HELP)
	{
		ft_dprintf(1, "%s: help:\n" LS_HELP, ls->ex);
		exit(0);
	}
	return (NULL);
}

int			main(int ac, char **av)
{
	t_ls	ls;

	ls.ex = ft_strrchr(av[0], '/') + 1;
	ls.aff_dir = 0;
	ls.flag = 0;
	ls_opts(ac, av, &ls);
	return (0);
}
