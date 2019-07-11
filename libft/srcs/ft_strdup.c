/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:49:01 by auverneu          #+#    #+#             */
/*   Updated: 2019/07/11 20:04:03 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = NULL;
	str = (char *)malloc((ft_strlen(s1) + 1));
	if (str)
		ft_strcpy(str, s1);
	return (str);
}
