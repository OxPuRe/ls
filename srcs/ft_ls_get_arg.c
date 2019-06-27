/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_get_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:57:52 by auverneu          #+#    #+#             */
/*   Updated: 2019/06/27 05:38:10 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_file(int jf, t_var *v, t_infols *file, t_ls *ls)
{
	char		*dir;

	if (jf > 0)
	{
		dir = ft_strdup(".");
		v->s.s.tmp = jf;
		ft_ls_fill(file, ls, &dir, v);
		ft_ls_print(file, ls, v, 0);
	}
	else
		free(file);
}

static void		ft_dir(int j, int jf, t_var *v, t_ls *ls)
{
	char		*dir;

	if (j > 0)
	{
		if (jf > 0)
			ft_printf("\n");
		v->s.s.tmp = j;
		ls->nbe = j;
		dir = ft_strdup(".");
		ft_ls_fill(ls->arg, ls, &dir, v);
	}
	else
		exit(0);
}

static void		ft_get_stat(char *av, t_var *v, t_ls *ls)
{
	if (lstat(av, &v->st) == -1)
		ls_exit(LS_E_STD_EXIT, av, ls);
}

void			ft_recup_arg(t_ls *ls, char **av, int ac, int i)
{
	t_var		v;
	t_infols	*file;

	v.s.init = 0;
	v.nbd = 0;
	v.nbf = 0;
	ls->nbe = (ac - i) ? (ac - i) : 1;
	v.s.s.tmp = ls->nbe;
	if (!(ls->arg = malloc(sizeof(t_infols) * ls->nbe)))
		ls_exit(LS_E_STD_EXIT, NULL, ls);
	if (!(file = malloc(sizeof(t_infols) * ls->nbe)))
		ls_exit(LS_E_STD_EXIT, NULL, ls);
	if ((ac - i) != 0)
		while (i < ac)
		{
			ft_get_stat(av[i], &v, ls);
			if (S_ISDIR(v.st.st_mode) || av[i][ft_strlen(av[i]) - 1] == '/')
				ls->arg[v.nbd++].name = ft_strdup(av[i++]);
			else
				file[v.nbf++].name = ft_strdup(av[i++]);
		}
	else
		ls->arg[v.nbd++].name = ft_strdup(".");
	ft_file(v.nbf, &v, file, ls);
	ft_dir(v.nbd, v.nbf, &v, ls);
}
