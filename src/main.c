/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <@student.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:45:51 by                   #+#    #+#             */
/*   Updated: 2018/05/16 17:07:09 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_core_ls(int ac, char **av)
{
	DIR				*rep;
	char			*rep_name;
	struct dirent	*rep_info;
	t_listls		*info;
	int				prc_size;

	rep = NULL;
	rep_info = NULL;
	info = NULL;
	if (ac == 1)
		rep_name = "./";
	else
		rep_name = av[1];
	if (!(rep = opendir(rep_name)))
		exit(1);
	while ((rep_info = readdir(rep)) != NULL)
	{
		ft_infolst_ls(info, &prc_size, rep_info->d_name);
	}
	ft_putstr("Here\n");
	printf("%c%s %2lu %s  %s  %lu %s %s\n", info->type, info->rights,
		info->nb_link, info->owner, info->group, info->size, info->date,
		rep_info->d_name);
	return (0);
}

int		main(int ac, char **av)
{
	return (ft_core_ls(ac, av));
}
