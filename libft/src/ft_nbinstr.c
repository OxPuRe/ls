/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbinstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 23:13:27 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/17 20:24:51 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_nbinstr(char const *s)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (s[0] == '\0')
		return (0);
	while (s[j])
	{
		while (s[j] && ft_isdigit(s[j]))
		{
			if ((!k && ft_isdigit(s[j + 1])) || (!k && !ft_isdigit(s[j - 1])))
			{
				k = 1;
				i++;
			}
			j++;
		}
		while (!ft_isdigit(s[j]) && s[j])
			j++;
		k = 0;
	}
	return (i);
}
