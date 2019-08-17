/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:18:39 by auverneu          #+#    #+#             */
/*   Updated: 2019/08/17 02:14:30 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static struct timespec	ls_get_tspc(struct stat *st, t_ls *ls)
{
	if (ls->flag & LS_F_ACCESS)
		return (st->st_atimespec);
	else if (ls->flag & LS_F_STATUS)
		return (st->st_ctimespec);
	else if (ls->flag & LS_F_CREATION)
		return (st->st_birthtimespec);
	else
		return (st->st_mtimespec);
}

void					ls_mode(t_info *info, t_ls *ls)
{
	info->mode[0] = '-';
	info->mode[0] = (S_ISDIR(info->stat.st_mode)) ? 'd' : info->mode[0];
	info->mode[0] = (S_ISCHR(info->stat.st_mode)) ? 'c' : info->mode[0];
	info->mode[0] = (S_ISBLK(info->stat.st_mode)) ? 'b' : info->mode[0];
	info->mode[0] = (S_ISFIFO(info->stat.st_mode)) ? 'p' : info->mode[0];
	info->mode[0] = (S_ISLNK(info->stat.st_mode)) ? 'l' : info->mode[0];
	info->mode[0] = (S_ISSOCK(info->stat.st_mode)) ? 's' : info->mode[0];
	info->mode[1] = (info->stat.st_mode & S_IRUSR) ? 'r' : '-';
	info->mode[2] = (info->stat.st_mode & S_IWUSR) ? 'w' : '-';
	info->mode[3] = (info->stat.st_mode & S_IXUSR) ? 'x' : '-';
	if (info->stat.st_mode & S_ISUID)
		info->mode[3] = (info->mode[3] == 'x') ? 's' : 'S';
	info->mode[4] = (info->stat.st_mode & S_IRGRP) ? 'r' : '-';
	info->mode[5] = (info->stat.st_mode & S_IWGRP) ? 'w' : '-';
	info->mode[6] = (info->stat.st_mode & S_IXGRP) ? 'x' : '-';
	if (info->stat.st_mode & S_ISGID)
		info->mode[6] = (info->mode[6] == 'x') ? 's' : 'S';
	info->mode[7] = (info->stat.st_mode & S_IROTH) ? 'r' : '-';
	info->mode[8] = (info->stat.st_mode & S_IWOTH) ? 'w' : '-';
	info->mode[9] = (info->stat.st_mode & S_IXOTH) ? 'x' : '-';
	if (info->stat.st_mode & S_ISVTX)
		info->mode[9] = (info->mode[9] == 'x') ? 't' : 'T';
	info->mode[10] = '\0';
	info->size = info->stat.st_size;
	info->timespec = ls_get_tspc(&info->stat, ls);
}

void					ls_info(t_info *info, t_print *p, t_ls *ls)
{
	struct passwd		*usr;
	struct group		*grp;

	ls_mode(info, ls);
	if ((usr = getpwuid(info->stat.st_uid)))
		info->owner = ft_strdup(usr->pw_name);
	else
		info->owner = ft_itoa(info->stat.st_uid);
	if ((grp = getgrgid(info->stat.st_gid)))
		info->group = ft_strdup(grp->gr_name);
	else
		info->group = ft_itoa(info->stat.st_gid);
	p->s.s.lk = ft_max((ft_intlen((int)info->stat.st_nlink)), p->s.s.lk);
	p->s.s.own = ft_max((ft_strlen(info->owner)), p->s.s.own);
	p->s.s.grp = ft_max((ft_strlen(info->group)), p->s.s.grp);
	p->s.s.sz = ft_max(ft_intlen((int)info->size), p->s.s.sz);
	if (info->mode[0] == 'c' || info->mode[0] == 'b')
	{
		p->s.s.min = ft_max(ft_intlen((int)minor(info->stat.st_rdev)),
		p->s.s.min);
		p->s.s.maj = ft_max(ft_intlen((int)major(info->stat.st_rdev)),
		p->s.s.maj);
	}
}
