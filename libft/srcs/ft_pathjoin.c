/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:18:00 by auverneu          #+#    #+#             */
/*   Updated: 2019/07/20 19:21:11 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** char *ft_pathjoin(const char *s1, const char *s2)
** This function concatenate two strings adding a "/" between its.
** s1,s2 The strings to concatenate.
** The allocated string containing the concatenated path.
** NULL On memory allocation errors.
*/

char		*ft_pathjoin(const char *s1, const char *s2)
{
	char	*ret;
	int		mode;
	size_t	i;
	size_t	j;

	mode = (ft_strequ(s1, "/")) ? 0 : 1;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
		+ mode + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	(mode) ? ret[i++] = '/' : (0);
	j = 0;
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}
