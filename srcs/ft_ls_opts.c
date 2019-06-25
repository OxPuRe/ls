/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_opts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:27:13 by auverneu          #+#    #+#             */
/*   Updated: 2019/06/25 05:22:46 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_file(int jf, t_var *v, t_infols *file, t_ls *ls)
{
	if (jf > 0)
	{
		v->s.s.tmp = jf;
		ft_ls_fill(file, ls, "./", v);
		ft_ls_print(file, ls, v, 0);
	}
}

static void		ft_dir(int j, int jf, t_var *v, t_ls *ls)
{
	if (j > 0)
	{
		if (jf > 0)
			ft_printf("\n");
		v->s.s.tmp = j;
		ls->nbe = j;
		ft_ls_fill(ls->arg, ls, "", v);
	}
	else
		exit(0);
}

static void		ft_recup_arg(t_ls *ls, char **av, int ac, int i)
{
	int			j;
	int			jf;
	t_var		v;
	t_infols	*file;

	v.s.init = 0;
	j = 0;
	jf = 0;
	ls->nbe = (ac - i) ? (ac - i) : 1;
	v.s.s.tmp = ls->nbe;
	if (!(ls->arg = malloc(sizeof(t_infols) * ls->nbe)))
		ls_exit(LS_E_STD_EXIT, NULL, ls);
	if (!(file = malloc(sizeof(t_infols) * ls->nbe)))
		ls_exit(LS_E_STD_EXIT, NULL, ls);
	if ((ac - i) != 0)
		while (i < ac)
		{
			if (av[i][0] == '/')
				lstat(av[i], &v.st);
			else
				lstat(ft_strjoin("./", av[i]), &v.st);
			if (S_ISDIR(v.st.st_mode) || av[i][ft_strlen(av[i]) - 1] == '/')
				ls->arg[j++].name = ft_strdup(av[i++]);
			else
				file[jf++].name = ft_strdup(av[i++]);
		}
	else
	{
		ls->arg[0].name = ft_strdup(".");
		j++;
	}
	ft_file(jf, &v, file, ls);
	ft_dir(j, jf, &v, ls);
}

static void		ft_recup_flag(char *av, t_ls *ls)
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
		if (*av == 'u' || *av == 'U' || *av == 'c')
			ls->flag &= ~(LS_F_STATUS | LS_F_ACCESS | LS_F_CREATION);
		ls->flag |= 1U << rot;
		av++;
	}
}

void			ft_ls_opts(int ac, char **av, t_ls *ls)
{
	int			i;

	i = 1;
	while (i < ac && *(av[i]) == '-' && ft_strlen(av[i]) != 1 &&
		!ft_strequ(av[i], "--"))
	{
		ft_recup_flag(av[i++], ls);
	}
	if (ft_strequ(av[i], "--"))
		i++;
	if (ls->flag & LS_F_NOSORT)
		ls->flag |= LS_F_ALL;
	ft_recup_arg(ls, av, ac, i);
}
