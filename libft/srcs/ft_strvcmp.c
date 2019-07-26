/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:47:31 by auverneu          #+#    #+#             */
/*   Updated: 2019/07/26 04:28:59 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_strvcmp(const void *s1, const void *s2)
{
	char	**ss1;
	char	**ss2;

	ss1 = ((char **)s1);
	ss2 = ((char **)s2);
	return (ft_strcmp(*ss1, *ss2));
}
