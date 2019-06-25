/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:04:01 by auverneu          #+#    #+#             */
/*   Updated: 2019/06/25 03:57:09 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_cmpstring(const void *f1, const void *f2)
{
	t_infols	*fl1;
	t_infols	*fl2;

	fl1 = ((t_infols *)f1);
	fl2 = ((t_infols *)f2);
	return (ft_strcmp(fl1->name, fl2->name));
}

static int		ft_cmptime(const void *f1, const void *f2)
{
	t_infols	*fl1;
	t_infols	*fl2;

	fl1 = ((t_infols *)f1);
	fl2 = ((t_infols *)f2);
	if (fl1->tme_spec.tv_sec != fl2->tme_spec.tv_sec)
		return ((fl1->tme_spec.tv_sec > fl2->tme_spec.tv_sec) ? -1 : 1);
	if (fl1->tme_spec.tv_nsec != fl2->tme_spec.tv_nsec)
		return ((fl1->tme_spec.tv_nsec > fl2->tme_spec.tv_nsec) ? -1 : 1);
	return (ft_strcmp(fl1->name, fl2->name));
}

static int		ft_cmpsize(const void *f1, const void *f2)
{
	t_infols	*fl1;
	t_infols	*fl2;

	fl1 = ((t_infols *)f1);
	fl2 = ((t_infols *)f2);
	if (fl1->size != fl2->size)
		return ((fl1->size > fl2->size) ? -1 : 1);
	return (ft_strcmp(fl1->name, fl2->name));
}

void			ft_ls_sort(t_infols *info, int flag, int nbe)
{
	if (flag & LS_F_SIZE)
		ft_qsort(info, nbe, sizeof(t_infols), &ft_cmpsize);
	else if (flag & LS_F_TIME)
		ft_qsort(info, nbe, sizeof(t_infols), &ft_cmptime);
	else
		ft_qsort(info, nbe, sizeof(t_infols), &ft_cmpstring);
	if (flag & LS_F_REVERSE)
		ft_revert(info, nbe, sizeof(t_infols));
}
