/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:04:01 by auverneu          #+#    #+#             */
/*   Updated: 2019/06/06 21:22:10 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_cmpstring(const void *a, const void *b)
{
	return (ft_strcmp(*((char *const *)a), *((char *const *)b)));
}

static int		ft_cmpsize(const void *f1, const void *f2)
{
	t_infols	*fl1;
	t_infols	*fl2;

	fl1 = *((t_infols **)f1);
	fl2 = *((t_infols **)f2);
	if (fl1->size != fl2->size)
		return ((fl1->size > fl2->size) ? -1 : 1);
	return (ft_strcmp(fl1->name, fl2->name));
}

void			ft_ls_sort(t_infols *info, int flag, int nbe)
{
	if ((flag & F_SS))
		ft_qsort(info, nbe, sizeof(t_infols), &ft_cmpsize);
	else
		ft_qsort(info, nbe, sizeof(t_infols), &ft_cmpstring);
}
