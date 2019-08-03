/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:38:34 by auverneu          #+#    #+#             */
/*   Updated: 2019/08/03 04:06:13 by auverneu         ###   ########.fr       */
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
		info[i].name = mem->content;
		mem = mem->next;
		i++;
	}
	ft_lstdel(&first, ft_ls_del);
}

void		ft_ls_list_rec(t_list **mem, t_list **list, t_infols *info)
{
	if (*mem == NULL)
	{
		*mem = ft_lstnew(info, sizeof(t_infols));
		*list = *mem;
	}
	else
	{
		(*list)->next = ft_lstnew(info, sizeof(t_infols));
		*list = (*list)->next;
	}
}

void		ft_ls_list(t_list **mem, t_list **list, char *name)
{
	if (*mem == NULL)
	{
		*mem = ft_lstnew(name, sizeof(char) * (ft_strlen(name) + 1));
		*list = *mem;
	}
	else
	{
		(*list)->next = ft_lstnew(name, sizeof(char) * (ft_strlen(name) + 1));
		*list = (*list)->next;
	}
}

char		*ls_get_lnk(char *dir, char *name, t_var *v, t_ls *ls)
{
	size_t	size;
	char	*str;
	char	*tmp;

	size = v->st.st_size > 0 ? (size_t)(v->st.st_size + 1) : LS_SL_BUFF;
	while (1)
	{
		if (!(str = (char *)malloc(sizeof(char) * size)))
			ls_exit(LS_E_STD_EXIT, NULL, ls);
		tmp = ls_get_tmp(name, dir, ls);
		if (readlink(tmp, str, size) == -1)
			ls_exit(LS_E_STD_EXIT, name, ls);
		free(tmp);
		(v->st.st_size > 0) ? str[size - 1] = '\0' : (0);
		if (ft_strnlen(str, size) == size)
		{
			free(str);
			size += LS_SL_BUFF;
		}
		else
			break ;
	}
	return (str);
}

void		*ft_malloc_ls(size_t size, t_ls *ls)
{
	void	*ret;

	if (!(ret = malloc(size)))
		ls_exit(LS_E_STD_EXIT, NULL, ls);
	return (ret);
}
