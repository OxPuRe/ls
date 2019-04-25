/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:45:51 by auverneu          #+#    #+#             */
/*   Updated: 2019/04/25 16:48:00 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int					ft_ls_error(int err, char *str)
{
	if (err == ILL_OPT)
		printf("%s%c\n%s", "ft_ls: illegal option -- ", str[0], "usage: ft_ls [-1aAcCdflrRtuUs] [file ...]\n");
	else if (err == ALLOC_F)
		printf("test");
	return (-1);
}



int					main(int ac, char **av)
{
	t_stls		ls;
	t_infols		*info;

	ls.ex = av[0];
	ls.flag = 0;
	info = ft_ls_opts(ac, av, &ls);
	//if (!(ls.flag & (F_F | F_UU)))
	//	ft_ls_sort(&ls, 0);
	ft_ls_core(&ls, info);
	return (0);
}