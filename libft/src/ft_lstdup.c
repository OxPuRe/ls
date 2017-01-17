/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:22:19 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/14 17:28:18 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*new;
	t_list	*mem;

	new = ft_lstnew(lst->content, lst->content_size);
	if (!new)
		return (NULL);
	mem = new;
	lst = lst->next;
	while (lst)
	{
		mem->next = ft_lstnew(lst->content, lst->content_size);
		if (!mem->next)
			return (NULL);
		mem = mem->next;
		lst = lst->next;
	}
	return (new);
}
