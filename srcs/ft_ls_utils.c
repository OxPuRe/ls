/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:38:34 by auverneu          #+#    #+#             */
/*   Updated: 2019/07/11 20:27:07 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ls_del(void *content, size_t size)
{
	(void)content;
	(void)size;
}

void		ft_ls_convert(t_list *mem, t_infols *info, int nbe)
{
	int		i;
	t_list	*first;

	i = 0;
	first = mem;
	while (i < nbe)
	{
	
		info[i].name = ft_strdup(mem->content);
		printf("convert %s\n", info[i].name);
		mem = mem->next;
		i++;
	}
	ft_lstdel(&first, ft_ls_del);
}

void		ft_ls_list(t_list **mem, t_list **list, char *name)
{
	if (*mem == NULL)
	{
		printf("list %s\n", name);
		*mem = ft_lstnew(name, (ft_strlen(name) + 1) * sizeof(char));
		*list = *mem;
	}
	else
	{
		(*list)->next = ft_lstnew(name, (ft_strlen(name) + 1) * sizeof(char));
		*list = (*list)->next;
	}
}

void		*ls_exit(int mode, void *arg, t_ls *ls)
{
	if (mode == LS_E_STD_EXIT || mode == LS_E_STD)
	{
		ft_dprintf(2, "%s: ", ls->ex);
		perror((char *)arg);
		if (mode == LS_E_STD_EXIT)
			exit(1);
	}
	else if (mode == LS_E_ARG)
	{
		ft_dprintf(2, "%s: illegal option -- %c\n"
			"usage: ft_ls [-" LS_OPTS " " LS_H_OPT "] [file ...]\n",
			ls->ex, *(char *)arg);
		exit(1);
	}
	else if (mode == LS_E_HELP)
	{
		ft_dprintf(1, "%s: help:\n" LS_HELP, ls->ex);
		exit(0);
	}
	return (NULL);
}
