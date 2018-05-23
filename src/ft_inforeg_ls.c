/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inforeg_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:21:55 by auverneu          #+#    #+#             */
/*   Updated: 2018/05/23 17:50:25 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int				ft_inforeg_ls(unsigned short winsz, int flags, char **arg)
{
	t_regls		*info;

	if (!(rep = opendir(rep_name)))
		exit (1);
	winsz = 0;
	printf("%s\t\t", info->name);
	return (0);
}

	while ((rep_info = readdir(rep)) != NULL)
