/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:30:09 by auverneu          #+#    #+#             */
/*   Updated: 2019/07/24 08:47:34 by auverneu         ###   ########.fr       */
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
