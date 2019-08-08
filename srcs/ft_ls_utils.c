/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:38:34 by auverneu          #+#    #+#             */
/*   Updated: 2019/08/09 00:47:46 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_del(void *content, size_t size)
{
	free(content);
	(void)size;
}

char		*ls_get_tmp(char *dir, char *name, t_ls *ls)
{
	char	*tmp;

	if (name[0] == '/')
		tmp = ft_strdup(name);
	else
		tmp = ft_pathjoin(dir, name, 1, "/");
	if (!tmp)
		ls_exit(LS_E_STD_EXIT, NULL, ls);
	return (tmp);
}

void		ls_list(t_list **mem, t_list **list, t_info *info)
{
	if (*mem == NULL)
	{
		*mem = ft_lstnew(info, sizeof(t_info));
		*list = *mem;
	}
	else
	{
		(*list)->next = ft_lstnew(info, sizeof(t_info));
		*list = (*list)->next;
	}
}

void		*ls_malloc(size_t size, t_ls *ls)
{
	void	*ret;

	if (!(ret = malloc(size)))
		ls_exit(LS_E_STD_EXIT, NULL, ls);
	return (ret);
}
