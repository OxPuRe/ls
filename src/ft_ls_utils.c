/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:38:34 by auverneu          #+#    #+#             */
/*   Updated: 2019/05/29 19:10:37 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

time_t		ft_ls_time(struct stat *stat, int flag)
{
	if (!(flag & F_UU))
		return (stat->st_birthtimespec.tv_sec);
	else if (!(flag & F_U))
		return (stat->st_atimespec.tv_sec);
	else
		return (stat->st_mtimespec.tv_sec);
}

void		ft_ls_list(t_list **mem, t_list **list, char *name)
{
	if (*mem == NULL)
	{
		*mem = ft_lstnew(name, ft_strlen(name) + 1);
		*list = *mem;
	}
	else
	{
		(*list)->next = ft_lstnew(name, ft_strlen(name) + 1);
		*list = (*list)->next;
	}
}
