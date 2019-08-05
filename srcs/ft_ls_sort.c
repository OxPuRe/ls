/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:04:01 by auverneu          #+#    #+#             */
/*   Updated: 2019/08/05 06:30:03 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ls_cmpstring(const void *f1, const void *f2)
{
	t_info	*fl1;
	t_info	*fl2;

	fl1 = ((t_info *)f1);
	fl2 = ((t_info *)f2);
	return (ft_strcmp(fl1->name, fl2->name));
}

static int		ls_cmptime(const void *f1, const void *f2)
{
	t_info	*fl1;
	t_info	*fl2;

	fl1 = ((t_info *)f1);
	fl2 = ((t_info *)f2);
	if (fl1->timespec.tv_sec != fl2->timespec.tv_sec)
		return ((fl1->timespec.tv_sec > fl2->timespec.tv_sec) ? -1 : 1);
	if (fl1->timespec.tv_nsec != fl2->timespec.tv_nsec)
		return ((fl1->timespec.tv_nsec > fl2->timespec.tv_nsec) ? -1 : 1);
	return (ft_strcmp(fl1->name, fl2->name));
}

static int		ls_cmpsize(const void *f1, const void *f2)
{
	t_info	*fl1;
	t_info	*fl2;

	fl1 = ((t_info *)f1);
	fl2 = ((t_info *)f2);
	if (fl1->size != fl2->size)
		return ((fl1->size > fl2->size) ? -1 : 1);
	return (ft_strcmp(fl1->name, fl2->name));
}

void			ls_sort(t_info *info, int flag, int nbe)
{
	if (flag & LS_F_SIZE)
		ft_qsort(info, nbe, sizeof(t_info), &ls_cmpsize);
	else if (flag & LS_F_TIME)
		ft_qsort(info, nbe, sizeof(t_info), &ls_cmptime);
	else
		ft_qsort(info, nbe, sizeof(t_info), &ls_cmpstring);
	if (flag & LS_F_REVERSE)
		ft_revert(info, nbe, sizeof(t_info));
}
