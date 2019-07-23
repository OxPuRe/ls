/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_get_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:57:52 by auverneu          #+#    #+#             */
/*   Updated: 2019/07/23 03:07:01 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_file(int jf, t_var *v, t_infols *file, t_ls *ls)
{
	if (!(ls->arg = malloc(sizeof(t_infols))))
		ls_exit(LS_E_STD_EXIT, NULL, ls);
	if (jf > 0)
	{
		ls->arg[0].name = ft_strdup(".");
		v->s.s.tmp = jf;
		ft_ls_fill(file, ls, ls->arg[0].name, v);
		ft_ls_print(file, ls, v, 0);
	}
	else
		free(file);
}

static void		ft_dir(int j, int jf, t_var *v, t_ls *ls)
{
	int			i;

	if (j > 0)
	{
		if (jf > 0)
			ft_printf("\n");
		v->s.s.tmp = j;
		ls->nbe = j;
		i = 0;
		v->blk = 0;
		while (i < v->s.s.tmp)
		{
			if (lstat(ls->arg[i].name, &v->st) == -1)
				ls_exit(LS_E_STD_EXIT, ls->arg[i].name, ls);
			ft_lstbegin_ls(&ls->arg[i], v->st.st_mode);
			ft_lstend_ls(&ls->arg[i], v, ls);
			if (ls->flag & LS_F_LONG && ls->arg[i].type == 'l')
			{
				ls_get_l_pth(".", &ls->arg[i], v, ls);
			}
			i++;
		}
		if ((ls->flag & LS_F_NOSORT) == 0)
			ft_ls_sort(ls->arg, ls->flag, v->s.s.tmp);
		ft_ls_core(ls);
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
	t_infols	*dir;

	v.s.init = 0;
	v.nbd = 0;
	v.nbf = 0;
	ls->nbe = (ac - i) ? (ac - i) : 1;
	v.s.s.tmp = ls->nbe;
	if (!(dir = malloc(sizeof(t_infols) * ls->nbe)))
		ls_exit(LS_E_STD_EXIT, NULL, ls);
	if (!(file = malloc(sizeof(t_infols) * ls->nbe)))
		ls_exit(LS_E_STD_EXIT, NULL, ls);
	if ((ac - i) != 0)
		while (i < ac)
		{
			ft_get_stat(av[i], &v, ls);
			if (S_ISDIR(v.st.st_mode) || av[i][ft_strlen(av[i]) - 1] == '/')
			{
				dir[v.nbd].name = ft_strdup(av[i]);
				v.nbd++;
			}
			else
			{
				file[v.nbf].name = ft_strdup(av[i]);
				v.nbf++;
			}
			i++;
		}
	else
		dir[v.nbd++].name = ft_strdup(".");
	ft_file(v.nbf, &v, file, ls);
	ls->arg = dir;
	ft_dir(v.nbd, v.nbf, &v, ls);
}
