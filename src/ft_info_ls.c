/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:18:39 by auverneu          #+#    #+#             */
/*   Updated: 2018/05/28 22:20:21 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_structls	*ft_alloc_structls(void)
{
	t_structls	*new;

	if (!(new = (t_structls *)malloc(sizeof(t_structls))))
		return (NULL);
	if (!(new->rights = (char *)malloc(9 * sizeof(char))))
		{
			free(new);
			return (NULL);
		}
	new->size_len = 0;
	return (new);
}

void		ft_lstbegin_ls(t_structls *info, mode_t st_mode)
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

void		ft_lstend_ls(t_structls *info, struct stat *st_ls, int *prc)
{
	struct passwd	*user;
	struct group	*group;
	char			*tmp;

	tmp = NULL;
	info->nb_link = (unsigned long)st_ls->st_nlink;
	user = getpwuid(st_ls->st_uid);
	group = getgrgid(st_ls->st_gid);
	info->owner = user->pw_name;
	info->group = group->gr_name;
	info->size = (unsigned long)st_ls->st_size;
	*prc = ft_max((ft_intlen((int)info->size)), *prc);
	tmp = ctime(&st_ls->st_mtime);
	info->date = (char *)malloc(12 * sizeof(char));
	info->date = (char *)ft_memmove(info->date, &tmp[4], 12);
}

int			ft_info_ls(int flags, char *arg, int *prc)
{
	t_structls	*info;
	struct stat	st_ls;
	int			i;

	i = 0;
	lstat(name, &st_ls);
	if (!lstls)
		lstls = ft_lstnew();
	info = ft_alloc_structls();
	info->name = arg;
	ft_lstbegin_ls(info, st_ls.st_mode);
	if ((flags & F_L) != 0)
		ft_lstend_ls(info, &st_ls, *prc);
	return (0);
}

	while ((rep_info = readdir(rep)) != NULL)
