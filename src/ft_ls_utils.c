/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:38:34 by auverneu          #+#    #+#             */
/*   Updated: 2019/05/17 17:49:14 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ls_list(t_list *mem, t_list *list, char *name)
{

	if (mem == NULL)
	{
		mem = ft_lstnew(name, ft_strlen(name));
		list = mem;
	}
	else
	{
		list->next = ft_lstnew(name, ft_strlen(name));
		list = list->next;
	}
}
