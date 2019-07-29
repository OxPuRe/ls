/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:18:00 by auverneu          #+#    #+#             */
/*   Updated: 2019/07/28 23:52:28 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_pathjoin(const char *s1, const char *s2, int m, const char *mid)
{
	char	*ret;
	int		mode;
	size_t	i;
	size_t	j;
	int		cp;

	mode = (ft_strequ(s1, "/")) ? 0 : 1;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
		+ mode + m));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	cp = 0;
	if (mode)
		while (cp < m)
			ret[i++] = mid[cp++];
	j = 0;
	ft_strcpy(ret + i, s2);
	return (ret);
}
