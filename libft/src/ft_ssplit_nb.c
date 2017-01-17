/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssplit_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 13:57:18 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/01 14:37:20 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		*ft_ssplitnb(char const *s)
{
	int			*tab;
	size_t		count;
	size_t		i;
	char		*scp;

	scp = s;
	count = ft_nbinstr(s);
	tab = (int *)ft_memalloc(sizeof(int) * count);
	if (!tab)
		return (NULL);
	while (i < count)
	{
		tab[i] = ft_atoi(scp);
		while (*scp == '-' || ft_isdigit(*scp) || *scp == '+')
			scp++;
		i++;
	}
	return (tab);
}
