/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:16:22 by auverneu          #+#    #+#             */
/*   Updated: 2019/06/07 01:48:04 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_partition(t_list *tab, int begin, int end,
								int (*compar)(const void*, const void*))
{
	void		*pivot;
	int			i;
	int			j;

	pivot = (unsigned char *)tab->content + end;
	i = begin;
	j = begin;
	while (j < end)
	{
		if (compar((unsigned char *)tab->content + j, pivot) <= 0)
		{
			ft_memswap((unsigned char *)tab->content + i,
				(unsigned char *)tab->content + j, tab->content_size);
			i += tab->content_size;
		}
		j += tab->content_size;
	}
	ft_memswap((unsigned char *)tab->content + i, (unsigned char *)tab->content
		+ end, tab->content_size);
	return (i);
}

void			ft_sort(t_list *tab, int begin, int end,
					int (*compar)(const void*, const void*))
{
	int			p;

	if (begin < end)
	{
		p = ft_partition(tab, begin, end, compar);
		ft_sort(tab, begin, p - tab->content_size, compar);
		ft_sort(tab, p + tab->content_size, end, compar);
	}
}

void			ft_qsort(void *base, size_t nmemb, size_t size,
					int (*compar)(const void *, const void *))
{
	t_list		tab;

	tab.content = base;
	tab.content_size = size;
	ft_sort(&tab, 0, (int)(nmemb - 1) * size, compar);
}
