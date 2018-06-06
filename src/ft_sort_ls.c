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

#include <stdio.h>
#include <stdlib.h>

int		partitionner(int *tableau, int p, int r)
{
	int pivot;
	int	temp;
	int	i;
	int	j;

	pivot = tableau[p];
	i = p - 1;
	j = r + 1;
	while (1)
	{
		while (tableau[--j] > pivot)
			;
		while (tableau[++i] < pivot)
			;
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

void	ft_sort_ls(int *tableau, int p, int r)
{
	int	q;

	if (p < r)
	{
		q = partitionner(tableau, p, r);
		ft_sort_ls(tableau, p, q);
		ft_sort_ls(tableau, q + 1, r);
	}
}
