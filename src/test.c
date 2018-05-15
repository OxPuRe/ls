/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:18:39 by auverneu          #+#    #+#             */
/*   Updated: 2018/05/15 15:45:11 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_listls	*ft_alloc_listls(void)
{
	t_listls	*new;

	if (!(new = (t_listls *)malloc(sizeof(t_listls))))
		return (NULL);
	new->type = '\0';
	if (!(new->rights = (char *)malloc(9 * sizeof(char))))
		{
			free(new);
			return (NULL);
		}
	return (new);
}

void		ft_type_ls(t_listls *info, mode_t st_mode)
{
	if (st_mode & S_IFREG)
        info->type = '-';
    else if (st_mode & S_IFDIR)
        info->type = 'd';
    else if (st_mode & S_IFLNK)
        info->type = 'l';
    else if (st_mode & S_IFIFO)
        info->type = 'p';
    else if (st_mode & S_IFSOCK)
        info->type = 's';
    else if (st_mode & S_IFCHR)
        info->type = 'c';
    else if (st_mode & S_IFBLK)
        info->type = 'b';
}

void		ft_rights_ls(t_listls *info, mode_t st_mode)
{
	(st_mode & S_IRUSR) ? (info->rights[0] = 'r') : (info->rights[0] = '-');
    (st_mode & S_IWUSR) ? (info->rights[1] = 'w') : (info->rights[1] = '-');
    (st_mode & S_IXUSR) ? (info->rights[2] = 'x') : (info->rights[2] = '-');
    (st_mode & S_IRGRP) ? (info->rights[3] = 'r') : (info->rights[3] = '-');
    (st_mode & S_IWGRP) ? (info->rights[4] = 'w') : (info->rights[4] = '-');
    (st_mode & S_IXGRP) ? (info->rights[5] = 'x') : (info->rights[5] = '-');
    (st_mode & S_IROTH) ? (info->rights[6] = 'r') : (info->rights[6] = '-');
    (st_mode & S_IWOTH) ? (info->rights[7] = 'w') : (info->rights[7] = '-');
    (st_mode & S_IXOTH) ? (info->rights[8] = 'x') : (info->rights[8] = '-');
}

int			ft_info_ls(char **av)
{
	struct stat	st_ls;
	t_listls	*info;

	info = ft_alloc_listls();
	stat(av[1], &st_ls);
	ft_type_ls(info, st_ls.st_mode);
	ft_rights_ls(info, st_ls.st_mode);
	printf("%c%s\n", info->type, info->rights);
	return (0);
}
