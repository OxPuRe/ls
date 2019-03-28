/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:16:22 by auverneu          #+#    #+#             */
/*   Updated: 2018/06/01 13:00:29 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		partition(t_list *tab, int begin, int end, int(*compar)(const void*, const void*))
{
	void	*mem;
	int		i;
	int		j;

	mem = NULL;
	mem = ft_memcpy(mem, &tab->content[begin], tab->content_size);
	i = begin;
	j = end + 1;

	while (i < j)
	{
		while (compar((char *)tab->content + i * tab->content_size, mem) && i <= end)
			i += 1 * tab->content_size;
		while (compar(mem, (char *)tab->content + j * tab->content_size))
			j += 1 * tab->content_size;
		if (i < j)
			ft_memswap((char *)tab->content + i * tab->content_size, (char *)			tab->content + j * tab->content_size, tab->content_size);
	}
	ft_memswap((char *)tab->content + begin * tab->content_size, (char *)			tab->content + j * tab->content_size, tab->content_size);
	return (j);
}

void	ft_sort(t_list *tab, int begin, int end, int(*compar)(const void*, const void*))
{
	int	p;

	if (begin < end)
	{
		p = partition(tab, begin, end, compar);
		ft_sort(tab, begin, p - 1, compar);
		ft_sort(tab, p + 1, end, compar);
	}
}

void	ft_qsort(void *base, size_t nmemb, size_t size,
					int(*compar)(const void*, const void*))
{
	t_list	tab;

	tab.content = base;
	tab.content_size = size;
	ft_sort(&tab, 0, (int)nmemb, compar);
}