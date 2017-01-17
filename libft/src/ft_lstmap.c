/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 00:03:48 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/14 16:29:04 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*mem;

	new = ft_lstnew(lst->content, lst->content_size);
	if (new == NULL)
		return (NULL);
	new = f(new);
	mem = new;
	lst = lst->next;
	while (lst)
	{
		mem->next = ft_lstnew(lst->content, lst->content_size);
		if (mem->next == NULL)
			return (NULL);
		mem->next = f(mem->next);
		mem = mem->next;
		lst = lst->next;
	}
	return (new);
}
