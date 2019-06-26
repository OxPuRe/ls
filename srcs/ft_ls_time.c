/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:30:09 by auverneu          #+#    #+#             */
/*   Updated: 2019/06/26 00:30:47 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_get_tspc(t_var *v, t_ls *ls, t_infols *info)
{
	if (ls->flag & LS_F_ACCESS)
		ft_memcpy(&(info->tme_spec), &(v->st.st_atimespec),
			sizeof(struct timespec));
	else if (ls->flag & LS_F_STATUS)
		ft_memcpy(&(info->tme_spec), &(v->st.st_ctimespec),
			sizeof(struct timespec));
	else if (ls->flag & LS_F_CREATION)
		ft_memcpy(&(info->tme_spec), &(v->st.st_birthtimespec),
			sizeof(struct timespec));
	else
		ft_memcpy(&(info->tme_spec), &(v->st.st_mtimespec),
			sizeof(struct timespec));
}

time_t		ft_ls_time(struct stat *stat, int flag)
{
	if (!(flag & LS_F_CREATION))
		return (stat->st_birthtimespec.tv_sec);
	else if (!(flag & LS_F_ACCESS))
		return (stat->st_atimespec.tv_sec);
	else
		return (stat->st_mtimespec.tv_sec);
}
