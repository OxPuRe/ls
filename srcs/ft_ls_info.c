/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:18:39 by auverneu          #+#    #+#             */
/*   Updated: 2019/07/12 00:31:30 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_lstbegin_ls(t_infols *info, int i, mode_t mode)
{
	printf("2.1 ");
	info[i].type = '-';
	info[i].type = (S_ISDIR(mode)) ? 'd' : info[i].type;
	info[i].type = (S_ISCHR(mode)) ? 'c' : info[i].type;
	info[i].type = (S_ISBLK(mode)) ? 'b' : info[i].type;
	info[i].type = (S_ISFIFO(mode)) ? 'p' : info[i].type;
	info[i].type = (S_ISLNK(mode)) ? 'l' : info[i].type;
	info[i].type = (S_ISSOCK(mode)) ? 's' : info[i].type;
	printf("2.2 ");
	info[i].rights[0] = (mode & S_IRUSR) ? 'r' : '-';
	info[i].rights[1] = (mode & S_IWUSR) ? 'w' : '-';
	info[i].rights[2] = (mode & S_IXUSR) ? 'x' : '-';
	if (mode & S_ISUID)
		info[i].rights[2] = (info[i].rights[2] == 'x') ? 's' : 'S';
	printf("2.3 ");
	info[i].rights[3] = (mode & S_IRGRP) ? 'r' : '-';
	info[i].rights[4] = (mode & S_IWGRP) ? 'w' : '-';
	info[i].rights[5] = (mode & S_IXGRP) ? 'x' : '-';
	printf("2.4 ");
	if (mode & S_ISGID)
		info[i].rights[5] = (info[i].rights[5] == 'x') ? 's' : 'S';
	printf("2.5 ");
	info[i].rights[6] = (mode & S_IROTH) ? 'r' : '-';
	info[i].rights[7] = (mode & S_IWOTH) ? 'w' : '-';
	info[i].rights[8] = (mode & S_IXOTH) ? 'x' : '-';
	printf("2.6 ");
	if (mode & S_ISVTX)
		info[i].rights[8] = (info[i].rights[8] == 'x') ? 't' : 'T';
	printf("2.7 \n");
	info[i].rights[9] = '\0';
}

void				ft_lstend_ls(t_infols *info, int i, t_var *v, t_ls *ls)
{
	struct passwd	*user;
	struct group	*group;

printf("3.1 ");
	info[i].link = (unsigned long)v->st.st_nlink;
	v->s.s.s_lk = ft_max((ft_intlen((int)info[i].link)), v->s.s.s_lk);
printf("3.2 ");
	user = getpwuid(v->st.st_uid);
	group = getgrgid(v->st.st_gid);
printf("3.3 ");
	info[i].owner = user->pw_name;
	v->s.s.s_own = ft_max((ft_strlen(info[i].owner)), v->s.s.s_own);
	info[i].group = group->gr_name;
	v->s.s.s_grp = ft_max((ft_strlen(info[i].group)), v->s.s.s_grp);
	if (info[i].type == 'c' || info[i].type == 'b')
	{
		info[i].size = v->st.st_size;
		info[i].minor = minor(v->st.st_rdev);
		info[i].major = major(v->st.st_rdev);
		v->s.s.s_min = ft_max((ft_intlen((int)info[i].minor)), v->s.s.s_min);
		v->s.s.s_maj = ft_max((ft_intlen((int)info[i].major)), v->s.s.s_maj);
	}
	else
		info[i].size = v->st.st_size;
printf("3.4 ");
	v->s.s.s_sz = ft_max((ft_intlen((int)info[i].size)), v->s.s.s_sz);
	ls_get_tspc(v, ls, info);
printf("3.5\n");
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
		if (!(tmp = ft_strxjoin("000", dir, "/", info->name)))
			ls_exit(LS_E_STD_EXIT, NULL, ls);
		if (readlink(tmp, str, size) == -1)
			return (ls_exit(LS_E_STD, info->name, ls));
		(v->st.st_size > 0) ? str[size - 1] = '\0' : (0);
		free(tmp);
		if (ft_strnlen(str, size) == size)
			size += LS_SL_BUFF;
		else
			break ;
	}
	if (!(info->name = ft_strxjoin("101", info->name, " -> ", str)))
		ls_exit(LS_E_STD_EXIT, NULL, ls);
	return (NULL);
}

void				ft_ls_fill(t_infols *info, t_ls *ls, char *dir, t_var *v)
{
	int				i;
	char			*tmp;

	i = 0;
	v->blk = 0;
	while (i < v->s.s.tmp)
	{
		if (!(tmp = ft_strxjoin("000", dir, "/", info[i].name)))
			ls_exit(LS_E_STD_EXIT, NULL, ls);
	printf("1 %s\n", tmp);
		if (lstat(tmp, &v->st) == -1)
			ls_exit(LS_E_STD_EXIT, tmp, ls);
	printf("2 ");
		free(tmp);
		ft_lstbegin_ls(info, i, v->st.st_mode);
	printf("3 ");
		ft_lstend_ls(info, i, v, ls);
	printf("4\n");
		if (ls->flag & LS_F_LONG && info[i].type == 'l')
		{
			ls_get_l_pth(dir, &info[i], v, ls);
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
	t_var			*v;
	t_infols		*info;

	list = NULL;
	mem = NULL;
	if (!(v = malloc(sizeof(t_var))))
		ls_exit(LS_E_STD_EXIT, NULL, ls);
	v->s.init = 0;
	v->blk = 0;
	if (!(v->rep = opendir(ls->arg[i].name)))
		return (ls_exit(LS_E_STD, ls->arg[i].name, ls));
	while ((v->ri = readdir(v->rep)) != NULL)
		if (v->ri->d_name[0] != '.' || (!(v->ri->d_name[0] == '.' &&
		(v->ri->d_name[1] == 0 || (v->ri->d_name[1] == '.' &&
		v->ri->d_name[2] == 0))) && ls->flag & LS_F_AALL) ||
		ls->flag & LS_F_ALL)
		{
			ft_ls_list(&mem, &list, v->ri->d_name);
			v->s.s.tmp += 1;
		}
	closedir(v->rep);
	if (!(info = malloc(sizeof(t_infols) * v->s.s.tmp)))
		ls_exit(LS_E_STD_EXIT, NULL, ls);
	ft_ls_convert(mem, info, v->s.s.tmp);
	ft_ls_fill(info, ls, ls->arg[i].name, v);
	return (ft_ls_print(info, ls, v, i));
}
