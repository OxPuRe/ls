/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:18:39 by auverneu          #+#    #+#             */
/*   Updated: 2019/04/25 16:49:18 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_lstbegin_ls(t_infols *info, mode_t st_mode)
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
	info->rights[0] = (st_mode & S_IRUSR) ? 'r' : '-';
	info->rights[1] = (st_mode & S_IWUSR) ? 'w' : '-';
	info->rights[2] = (st_mode & S_IXUSR) ? 'x' : '-';
	info->rights[3] = (st_mode & S_IRGRP) ? 'r' : '-';
	info->rights[4] = (st_mode & S_IWGRP) ? 'w' : '-';
	info->rights[5] = (st_mode & S_IXGRP) ? 'x' : '-';
	info->rights[6] = (st_mode & S_IROTH) ? 'r' : '-';
	info->rights[7] = (st_mode & S_IWOTH) ? 'w' : '-';
	info->rights[8] = (st_mode & S_IXOTH) ? 'x' : '-';
	info->rights[9] = '\0';
}

void				ft_lstend_ls(t_infols *info, t_var *v)
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

void				ft_ls_convert(t_list *mem, t_infols *info, int nbe)
{
	int				i;

	i = 0;
	while (i < nbe)
	{
		info[i].name = mem->content;
		mem = mem->next;
		i++;
	}
}

void				ft_ls_fill(t_infols *info, t_stls *ls, char *dir,
								t_var *v)
{
	int				i;

	i = 0;
	while (i < v->tmp)
	{
		lstat(ft_strjoin(dir, info[i].name), &v->st);
		ft_lstbegin_ls(&info[i], v->st.st_mode);
		if ((ls->flag & F_L) != 0)
			ft_lstend_ls(&info[i], v);
		i++;
	}
	ft_ls_sort(info, ls);
}

t_infols			*ft_ls_info(char *dir, t_stls *ls)
{
	t_list			*list;
	t_list			*mem;
	t_var			v;
	t_infols		*info;

	mem = NULL;
	v.tmp = 0;
	v.rep = opendir(dir);
	while ((v.rep_i = readdir(v.rep)) != NULL)
	{
		if (mem == NULL)
		{
			mem = ft_lstnew(v.rep_i->d_name, ft_strlen(v.rep_i->d_name));
			list = mem;
		}
		else
		{
			list->next = ft_lstnew(v.rep_i->d_name, ft_strlen(v.rep_i->d_name));
			list = list->next;
		}
		v.tmp += 1;
	}
	info = malloc(sizeof(t_infols) * v.tmp);
	ft_ls_convert(mem, info, v.tmp);
	ft_ls_fill(info, ls, dir, &v);
	return (ft_ls_print(info, ls, &v));
}

//printf("(%s)\n", info[i].name);