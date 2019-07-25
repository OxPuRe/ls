/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:45:51 by auverneu          #+#    #+#             */
/*   Updated: 2019/07/25 01:55:32 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int					main(int ac, char **av)
{
	t_ls			*ls;

	ls = malloc(sizeof(t_ls));
	ls->ex = &av[0][2];
	ls->aff_dir = 0;
	ls->flag = 0;
	ft_ls_opts(ac, av, ls);
	return (0);
}
