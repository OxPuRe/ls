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
#include <ft_ls.h.h>

int		partitionner(int *tableau, int p, int r, size_t size,
						int(*compar)(const void*, const void*))
{
	int	temp;
	int	i;
	int	j;

	i = p;
	j = r;

	while (1)
	{
		if (i < j)
		{
			temp = tableau[i];
			tableau[i] = tableau[j];
			tableau[j] = temp;
		}
		else
			return (j);
	}
}

void	ft_sort_ls(int *tableau, int p, int r, size_t size,
						int(*compar)(const void*, const void*))
{
	int	pivot;

	if (p < r)
	{
		pivot = 0;
		pivot = partitionner(tableau, p, r, size, compar);
		ft_sort_ls(tableau, p, pivot - 1, size, compar);
		ft_sort_ls(tableau, pivot + 1, r, size, compar);
	}
}

void	ft_qsort(void *base, size_t nmemb, size_t size,
					int(*compar)(const void*, const void*))
{
	
	ft_sort_ls(base, 0, nmemb, size, compar)
}