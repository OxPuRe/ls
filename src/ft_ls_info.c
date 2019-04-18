/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:18:39 by auverneu          #+#    #+#             */
/*   Updated: 2019/04/18 19:25:15 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_lstbegin_ls(t_infols *info, mode_t st_mode)
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
	info->rights[9] = '\0';
}

void			ft_lstend_ls(t_infols *info, t_var *v)
{
	struct passwd	*user;
	struct group	*group;

	info->link = (unsigned long)v->st.st_nlink;
	v->s_link = ft_max((ft_intlen((int)info->link)), v->s_link);
	user = getpwuid(v->st.st_uid);
	group = getgrgid(v->st.st_gid);
	info->owner = user->pw_name;
	info->group = group->gr_name;
	info->size = (unsigned long)v->st.st_size;
	v->s_size = ft_max((ft_intlen((int)info->size)), v->s_size);
	info->date = ft_strdup(ctime(&v->st.st_mtime));
	v->blk += v->st.st_blocks;
}

void			ft_ls_convert(t_list *mem, t_infols *info)
{
	while (mem)
	{
		info->name = mem->content;
		mem = mem->next;
	}
}

void			ft_ls_fill(t_infols *info, t_structls *lsr, char *dir, t_var *v)
{
	int			i;

	i = 0;
	while (lsr->nbe--)
	{
		lstat(ft_strjoin(dir, info[i].name), &v->st);
		ft_lstbegin_ls(&info[i], v->st.st_mode);
		if ((lsr->flag & F_L) != 0)
			ft_lstend_ls(&info[i], v);
		i++;
	}
}

t_structls		*ft_ls_info(char *dir, t_structls *lsr)
{
	t_list		*list;
	t_list		*mem;
	t_var		v;
	t_infols	*info;

	mem = list;
	v.rep = opendir(dir);
	while ((v.rep_i = readdir(v.rep)) != NULL)
	{
		if (list)
			list = list->next;
		list = ft_lstnew(ft_strdup(v.rep_i->d_name), sizeof(char *));
		lsr->nbe += 1;
	}
	info = malloc(sizeof(t_infols) * lsr->nbe);
	ft_ls_convert(mem, info);
	ft_ls_fill(info, lsr, dir, &v);
	ft_ls_sort(lsr);
}