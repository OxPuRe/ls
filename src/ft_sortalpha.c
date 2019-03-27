/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:20:39 by auverneu          #+#    #+#             */
/*   Updated: 2018/05/29 13:12:53 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		ft_sortalpha(char **tab)
{
	int		i;
	int		j;
	int		max;
	char	*tmp;

	i = 0;
	j = 0;
	max = 0;
	while (tab[max])
		max++;
	while (i < max)
	{
		while (j < (max - i))
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
