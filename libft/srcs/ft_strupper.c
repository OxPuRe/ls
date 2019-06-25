/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 19:38:56 by auverneu          #+#    #+#             */
/*   Updated: 2016/06/06 18:02:50 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strupper(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strnew(ft_strlen(str));
	while (str[i])
	{
		tmp[i] = ft_toupper(str[i]);
		i++;
	}
	return (tmp);
}
