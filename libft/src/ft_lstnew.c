/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 22:38:13 by auverneu          #+#    #+#             */
/*   Updated: 2018/05/23 19:02:06 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	if ((lst = (t_list *)ft_memalloc(sizeof(t_list))))
	{
		if (content)
		{
			if ((lst->content = ft_memalloc(content_size)))
			{
				lst->content = ft_memcpy(lst->content, content, content_size);
				lst->content_size = content_size;
			}
			else
			{
				ft_memdel((void **)&lst);
				return (NULL);
			}
		}
		else
		{
			lst->content = NULL;
			lst->content_size = 0;
		}
		lst->next = NULL;
	}
	return (lst);
}
