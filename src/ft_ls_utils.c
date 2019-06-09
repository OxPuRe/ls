/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:38:34 by auverneu          #+#    #+#             */
/*   Updated: 2019/06/09 05:10:43 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

time_t		ft_ls_time(struct stat *stat, int flag)
{
	if (!(flag & LS_F_CREATION))
		return (stat->st_birthtimespec.tv_sec);
	else if (!(flag & LS_F_ACCESS))
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

void		ls_exit(int mode, void *arg, t_ls *ls)
{
	if (mode == LS_E_STD_EXIT || mode == LS_E_STD)
	{
		dprintf(2, "%s: ", ls->ex);
		perror((char *)arg);
		if (mode == LS_E_STD_EXIT)
			exit(2);
		ls->error = 1;
	}
	else if (mode == LS_E_ARG)
	{
		dprintf(2, "%s: illegal option -- %c\n"
			"usage: ft_ls [-" LS_OPTS " " LS_H_OPT "] [file ...]\n",
			ls->ex, *(char *)arg);
		exit(2);
	}
	else if (mode == LS_E_HELP)
	{
		dprintf(1, "%s: help:\n" LS_HELP, ls->ex);
		exit(0);
	}
}
