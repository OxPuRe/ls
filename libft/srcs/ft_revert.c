/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 22:43:19 by auverneu          #+#    #+#             */
/*   Updated: 2019/06/24 22:43:50 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function revert the given array
** Return:	The original array.
*/

void				*ft_revert(void *arr, size_t nitems, size_t width)
{
	unsigned char	*arr1;
	unsigned char	*arr2;

	arr1 = (unsigned char *)arr;
	arr2 = (unsigned char *)arr + ((nitems - 1) * width);
	while (arr1 < arr2)
	{
		ft_memswap(arr1, arr2, width);
		arr1 += width;
		arr2 -= width;
	}
	return (arr);
}
