/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 23:16:03 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/02 02:27:31 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*s;

	s = NULL;
	s = (char *)malloc(size * sizeof(char) + 1);
	if (s)
		ft_memset(s, (int)'\0', size + 1);
	return (s);
}
