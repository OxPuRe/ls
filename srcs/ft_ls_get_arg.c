/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_get_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:57:52 by auverneu          #+#    #+#             */
/*   Updated: 2019/08/05 10:40:47 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_file(int nbf, t_info *file, t_ls *ls)
{
	t_print		print;
	t_ls		lsr;

	lsr.nbe = 0;
	print.s.init = 0;
	print.nbe = 0;
	while ((int)print.nbe < nbf)
	{
		ls_info(&file[print.nbe], &print, ls);
		print.nbe++;
	}
	ls->path = (char**)ls_malloc(sizeof(char *), ls);
	if (nbf > 0)
	{
		if (!(ls->path[0] = ft_strdup(".")))
			ls_exit(LS_E_STD_EXIT, NULL, ls);
		ls_display(file, &print, ls, &lsr);
	}
	else
		free(file);
	free(ls->path);
}

static void		ls_dir(t_av *nb, t_info *dir, t_ls *ls)
{
	size_t		i;
	t_print		print;

	print.s.init = 0;
	print.nbe = 0;
	if (nb->n.n.d > 0)
	{
		if (nb->n.n.f > 0)
			ft_printf("\n");
		ls->nbe = nb->n.n.d;
		i = 0;
		while (i < ls->nbe)
			ls_info(&dir[i++], &print, ls);
		if ((ls->flag & LS_F_NOSORT) == 0)
			ls_sort(dir, ls->flag, ls->nbe);
		i = 0;
		ls->path = (char**)ls_malloc(sizeof(char *) * ls->nbe, ls);
		while (i < ls->nbe)
		{
			if (!(ls->path[i] = ft_strdup(dir[i].name)))
				ls_exit(LS_E_STD_EXIT, NULL, ls);
			i++;
		}
		ls_core(ls);
	}
	else
		exit(0);
}

static void		ls_arg_err(char **tab, int e, t_ls *ls)
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
	if (tab)
		free(tab);
}

static void		ls_test(char *av, t_info **arg, t_av *e, t_ls *ls)
{
	char		*lnk;
	struct stat st_l;

	if ((S_ISDIR(e->stat.st_mode) || av[ft_strlen(av) - 1] == '/') &&
	!(ls->flag & LS_F_DIR))
	{
		ft_strcpy(arg[1][e->n.n.d].name, av);
		arg[1][e->n.n.d++].stat = e->stat;
	}
	else if (S_ISLNK(e->stat.st_mode))
	{
		lnk = ls_print_link(".", 1, ls);
		lstat(lnk, &st_l);
		free(lnk);
		if (S_ISDIR(st_l.st_mode) && !(ls->flag & LS_F_LONG))
		{
			ft_strcpy(arg[1][e->n.n.d].name, av);
			arg[1][e->n.n.d++].stat = e->stat;
		}
		else
		{
			ft_strcpy(arg[0][e->n.n.f].name, av);
			arg[0][e->n.n.f++].stat = e->stat;
		}
	}
	else
	{
		ft_strcpy(arg[0][e->n.n.f].name, av);
		arg[0][e->n.n.f++].stat = e->stat;
	}
}

void			ls_recup_arg(char **av, t_ls *ls)
{
	t_info		*arg[2];
	char		**tab;
	t_av		elem;

	elem.n.init = 0;
	tab = (char **)ls_malloc(sizeof(char *) * ls->nbe, ls);
	arg[0] = (t_info*)ls_malloc(sizeof(t_info) * ls->nbe, ls);
	arg[1] = (t_info*)ls_malloc(sizeof(t_info) * ls->nbe, ls);
	if (ls->nbe)
	{
		while (ls->nbe)
		{
			if ((lstat(*av, &elem.stat)) == 0)
				ls_test(*av, arg, &elem, ls);
			else
				tab[elem.n.n.e++] = *av;
			ls->nbe--;
			av++;
		}
	}
	else
	{
		ft_strcpy(arg[1][0].name, ".");
		lstat(*av, &arg[1][0].stat);
	}
	ls_arg_err(tab, elem.n.n.e, ls);
	ls_file(elem.n.n.f, arg[0], ls);;
	ls_dir(&elem, arg[1], ls);
}
