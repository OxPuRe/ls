/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 05:27:15 by auverneu          #+#    #+#             */
/*   Updated: 2016/08/25 05:27:33 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_reverse(char *str)
{
	int		i;
	int		j;
	int		mid;
	char	c;

	i = 0;
	j = ft_strlen(str) - 1;
	if ((j % 2) == 1)
		mid = (j - 1) / 2;
	else
		mid = j / 2;
	while (i <= mid)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		j--;
		i++;
	}
}
