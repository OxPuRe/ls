/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inforeg_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:21:55 by auverneu          #+#    #+#             */
/*   Updated: 2018/05/21 15:47:18 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int				ft_inforeg_ls(char *name, int flags)
{
	t_regls		*info;
	struct stat	st_ls;

	if (!(info = (t_regls *)malloc(sizeof(t_regls))))
		return (-1);
	lstat(name, &st_ls);
	info->name = name;
	if (st_ls.st_mode & S_IFREG)
		info->type = '-';
	else if (st_ls.st_mode & S_IFDIR)
		info->type = 'd';
	else if (st_ls.st_mode & S_IFLNK)
		info->type = 'l';
	else if (st_ls.st_mode & S_IFIFO)
		info->type = 'p';
	else if (st_ls.st_mode & S_IFSOCK)
		info->type = 's';
	else if (st_ls.st_mode & S_IFCHR)
		info->type = 'c';
	else if (st_ls.st_mode & S_IFBLK)
		info->type = 'b';
	if (!(flags & F_A) && (info->name[0] == '.'))
		return (0);
	printf("%s\n", info->name);
	return (0);
}
