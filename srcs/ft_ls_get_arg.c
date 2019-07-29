/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_get_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:57:52 by auverneu          #+#    #+#             */
/*   Updated: 2019/07/29 05:07:55 by auverneu         ###   ########.fr       */
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
	free(ls->arg);
}

static void		ft_dir(int j, int jf, t_var *v, t_ls *ls)
{
	int			i;

	if (j > 0)
	{
		if (jf > 0)
			ft_printf("\n");
		ls->nbe = j;
		i = 0;
		v->blk = 0;
		while (i < ls->nbe)
		{
			if (lstat(ls->arg[i].name, &v->st) == -1)
				ls_exit(LS_E_STD_EXIT, ls->arg[i].name, ls);
			ft_lstbegin_ls(&ls->arg[i], v->st.st_mode);
			ft_lstend_ls(&ls->arg[i], v, ls);
			i++;
		}
		if ((ls->flag & LS_F_NOSORT) == 0)
			ft_ls_sort(ls->arg, ls->flag, ls->nbe);
		ft_ls_core(ls);
	}
	else
		exit(0);
}

static void		ft_arg_err(char **tab, int e, t_ls *ls)
{
	int			i;

	i = 0;
	if (e)
	{
		ft_qsort(tab, e, sizeof(char *), &ft_strvcmp);
		while (i < e)
		{
			ls_exit(LS_E_STD, tab[i], ls);
			i++;
		}
	}
	free(tab);
}

static void		ft_test(char *av, t_ls *ls, t_infols **arg, t_var *v)
{
	char		*lnk;
	t_var		vl;

	if ((S_ISDIR(v->st.st_mode) || av[ft_strlen(av) - 1] == '/') &&
	!(ls->flag & LS_F_DIR))
		arg[1][v->n.n.d++].name = ft_strdup(av);
	else if ((S_ISLNK(v->st.st_mode)))
	{
		lnk = ls_get_lnk(".", av, v, ls);
		lstat(lnk, &vl.st);
		if (S_ISDIR(vl.st.st_mode) && !(ls->flag & LS_F_LONG))
			arg[1][v->n.n.d++].name = ft_strdup(av);
		else
			arg[0][v->n.n.f++].name = ft_strdup(av);
	}
	else
		arg[0][v->n.n.f++].name = ft_strdup(av);
}

void			ft_recup_arg(t_ls *ls, char **av, int ac, int i)
{
	t_var		v;
	t_infols	*arg[2];
	char		**tab;

	v.s.init = 0;
	v.n.init = 0;
	ls->nbe = (ac - i) ? (ac - i) : 1;
	v.s.s.tmp = ls->nbe;
	tab = NULL;
	tab = (char **)ft_malloc_ls(sizeof(char *) * ac, ls);
	arg[1] = (t_infols*)ft_malloc_ls(sizeof(t_infols) * ls->nbe, ls);
	arg[0] = (t_infols*)ft_malloc_ls(sizeof(t_infols) * ls->nbe, ls);
	if ((ac - i) != 0)
		while (i < ac)
			if ((lstat(av[i], &v.st)) == 0)
				ft_test(av[i++], ls, arg, &v);
			else
				tab[v.n.n.e++] = av[i++];
	else
		arg[(ls->flag & LS_F_DIR) ? 0 : 1]
		[(ls->flag & LS_F_DIR) ? v.n.n.f++ : v.n.n.d++].name = ft_strdup(".");
	ft_arg_err(tab, v.n.n.e, ls);
	ft_file(v.n.n.f, &v, arg[0], ls);
	ls->arg = arg[1];
	ft_dir(v.n.n.d, v.n.n.f, &v, ls);
}
