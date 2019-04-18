/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:45:51 by auverneu          #+#    #+#             */
/*   Updated: 2019/04/18 11:57:35 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_error_ls(int err, char *str)
{
	if (err == ILL_OPT)
		printf("%s%c\n%s", "ft_ls: illegal option -- ", str[0], "usage: ft_ls [-1aAcCdflrRtuUs] [file ...]\n");
	else if (err == ALLOC_F)
		printf("test");
	return (-1);
}

int		ft_cmpstring(const void *a, const void *b)
{
	return (ft_strcmp(*((char * const *)a), *((char * const *)b)));
}

int		main(int ac, char **av)
{
	t_structls		ls;

	ls.ex = ft_strdup(av[0]);
	ls.flag = 0;
	ft_opts_ls(ac, av, &ls);
	// if (!paths)
	// 	return (ERROR);
//printf("{ %d }\n", i);
	if (ls.flag & (F_F || F_UU))
		ft_qsort(ls.elem, ls.nbe, sizeof(char *), &ft_cmpstring);
	ft_ls_core(&ls, ls.elem);
	return (0);
}