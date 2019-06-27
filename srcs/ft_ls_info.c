/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:18:39 by auverneu          #+#    #+#             */
/*   Updated: 2019/06/27 06:30:01 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_lstbegin_ls(t_infols *info, mode_t mode)
{
	info->type = '-';
	info->type = (S_ISDIR(mode)) ? 'd' : info->type;
	info->type = (S_ISCHR(mode)) ? 'c' : info->type;
	info->type = (S_ISBLK(mode)) ? 'b' : info->type;
	info->type = (S_ISFIFO(mode)) ? 'p' : info->type;
	info->type = (S_ISLNK(mode)) ? 'l' : info->type;
	info->type = (S_ISSOCK(mode)) ? 's' : info->type;
	info->rights[0] = (mode & S_IRUSR) ? 'r' : '-';
	info->rights[1] = (mode & S_IWUSR) ? 'w' : '-';
	info->rights[2] = (mode & S_IXUSR) ? 'x' : '-';
	if (mode & S_ISUID)
		info->rights[2] = (info->rights[2] == 'x') ? 's' : 'S';
	info->rights[3] = (mode & S_IRGRP) ? 'r' : '-';
	info->rights[4] = (mode & S_IWGRP) ? 'w' : '-';
	info->rights[5] = (mode & S_IXGRP) ? 'x' : '-';
	if (mode & S_ISGID)
		info->rights[5] = (info->rights[5] == 'x') ? 's' : 'S';
	info->rights[6] = (mode & S_IROTH) ? 'r' : '-';
	info->rights[7] = (mode & S_IWOTH) ? 'w' : '-';
	info->rights[8] = (mode & S_IXOTH) ? 'x' : '-';
	if (mode & S_ISVTX)
		info->rights[8] = (info->rights[8] == 'x') ? 't' : 'T';
	info->rights[9] = '\0';
}

void				ft_lstend_ls(t_infols *info, t_var *v, t_ls *ls)
{
	struct passwd	*user;
	struct group	*group;

	info->link = (unsigned long)v->st.st_nlink;
	v->s.s.s_lk = ft_max((ft_intlen((int)info->link)), v->s.s.s_lk);
	user = getpwuid(v->st.st_uid);
	group = getgrgid(v->st.st_gid);
	info->owner = user->pw_name;
	v->s.s.s_own = ft_max((ft_strlen(info->owner)), v->s.s.s_own);
	info->group = group->gr_name;
	v->s.s.s_grp = ft_max((ft_strlen(info->group)), v->s.s.s_grp);
	if (info->type == 'c' || info->type == 'b')
	{
		info->size = v->st.st_size;
		info->minor = minor(v->st.st_rdev);
		info->major = major(v->st.st_rdev);
		v->s.s.s_min = ft_max((ft_intlen((int)info->minor)), v->s.s.s_min);
		v->s.s.s_maj = ft_max((ft_intlen((int)info->major)), v->s.s.s_maj);
	}
	else
		info->size = v->st.st_size;
	v->s.s.s_sz = ft_max((ft_intlen((int)info->size)), v->s.s.s_sz);
	ls_get_tspc(v, ls, info);
	v->blk += v->st.st_blocks;
}

static void			*ls_get_l_pth(char *dir, t_infols *info, t_var *v, t_ls *ls)
{
	size_t			size;
	char			*str;
	char			*tmp;

	size = v->st.st_size > 0 ? (size_t)(v->st.st_size + 1) : LS_SL_BUFF;
	while (1)
	{
		if (!(str = (char *)malloc(sizeof(char) * size)))
			ls_exit(LS_E_STD_EXIT, NULL, ls);
		tmp = ft_strjoin(dir, info->name);
		if (readlink(tmp, str, size) == -1)
			return (ls_exit(LS_E_STD, info->name, ls));
		(v->st.st_size > 0) ? str[size - 1] = '\0' : (0);
		free(tmp);
		if (ft_strnlen(str, size) == size)
			size += LS_SL_BUFF;
		else
			break ;
	}
	tmp = ft_strjoin(info->name, " -> ");
	free(info->name);
	info->name = ft_strjoin(tmp, str);
	free(str);
	free(tmp);
	return (NULL);
}

void				ft_ls_fill(t_infols *info, t_ls *ls, char **dir, t_var *v)
{
	int				i;
	char			*tmp;

	i = 0;
	v->blk = 0;
	tmp = *dir;
	if (!(*dir = ft_strxjoin("00", tmp, "/")))
		ls_exit(LS_E_STD_EXIT, NULL, ls);
	while (i < v->s.s.tmp)
	{
		if (!(tmp = ft_strxjoin("00", *dir, info[i].name)))
			ls_exit(LS_E_STD_EXIT, NULL, ls);	
	ft_printf("[%s]\n", tmp);
		lstat(tmp, &v->st);
		free(tmp);
		ft_lstbegin_ls(&info[i], v->st.st_mode);
		ft_lstend_ls(&info[i], v, ls);
		if (ls->flag & LS_F_LONG && info[i].type == 'l')
		{
			ls_get_l_pth(*dir, &info[i], v, ls);
		}
		i++;
	}
	if ((ls->flag & LS_F_NOSORT) == 0)
		ft_ls_sort(info, ls->flag, v->s.s.tmp);
}

t_ls				*ft_ls_info(t_ls *ls, int i)
{
	t_list			*list;
	t_list			*mem;
	t_var			v;
	t_infols		*info;

	list = NULL;
	mem = NULL;
	v.s.init = 0;
	v.blk = 0;
	if (!(v.rep = opendir(ls->arg[i].name)))
		return (ls_exit(LS_E_STD, ls->arg[i].name, ls));
	while ((v.ri = readdir(v.rep)) != NULL)
		if (v.ri->d_name[0] != '.' || (!(v.ri->d_name[0] == '.' &&
		(v.ri->d_name[1] == 0 || (v.ri->d_name[1] == '.' &&
		v.ri->d_name[2] == 0))) && ls->flag & LS_F_AALL) || ls->flag & LS_F_ALL)
		{
			ft_ls_list(&mem, &list, v.ri->d_name);
			v.s.s.tmp += 1;
		}
	closedir(v.rep);
	if (!(info = malloc(sizeof(t_infols) * v.s.s.tmp)))
		ls_exit(LS_E_STD_EXIT, NULL, ls);
	ft_ls_convert(mem, info, v.s.s.tmp);
	ft_ls_fill(info, ls, &ls->arg[i].name, &v);
	return (ft_ls_print(info, ls, &v, i));
}