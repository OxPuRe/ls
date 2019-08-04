/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:18:39 by auverneu          #+#    #+#             */
/*   Updated: 2019/08/04 12:00:48 by auverneu         ###   ########.fr       */
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

static void				ls_mode(char *mode, mode_t st_mode)
{
	mode[0] = '-';
	mode[0] = (S_ISDIR(st_mode)) ? 'd' : mode[0];
	mode[0] = (S_ISCHR(st_mode)) ? 'c' : mode[0];
	mode[0] = (S_ISBLK(st_mode)) ? 'b' : mode[0];
	mode[0] = (S_ISFIFO(st_mode)) ? 'p' : mode[0];
	mode[0] = (S_ISLNK(st_mode)) ? 'l' : mode[0];
	mode[0] = (S_ISSOCK(st_mode)) ? 's' : mode[0];
	mode[1] = (st_mode & S_IRUSR) ? 'r' : '-';
	mode[2] = (st_mode & S_IWUSR) ? 'w' : '-';
	mode[3] = (st_mode & S_IXUSR) ? 'x' : '-';
	if (st_mode & S_ISUID)
		mode[3] = (mode[3] == 'x') ? 's' : 'S';
	mode[4] = (st_mode & S_IRGRP) ? 'r' : '-';
	mode[5] = (st_mode & S_IWGRP) ? 'w' : '-';
	mode[6] = (st_mode & S_IXGRP) ? 'x' : '-';
	if (st_mode & S_ISGID)
		mode[6] = (mode[6] == 'x') ? 's' : 'S';
	mode[7] = (st_mode & S_IROTH) ? 'r' : '-';
	mode[8] = (st_mode & S_IWOTH) ? 'w' : '-';
	mode[9] = (st_mode & S_IXOTH) ? 'x' : '-';
	if (st_mode & S_ISVTX)
		mode[9] = (mode[9] == 'x') ? 't' : 'T';
	mode[10] = '\0';
}

void					ls_info(t_info *info, t_print *p, t_ls *ls)
{
	struct passwd		*usr;
	struct group		*grp;

	ls_mode(info->mode, info->stat.st_mode);
	if ((usr = getpwuid(info->stat.st_uid)))
		info->owner = ft_strdup(usr->pw_name);
	else
		info->owner = ft_itoa(info->stat.st_uid);
	if ((grp = getgrgid(info->stat.st_gid)))
		info->group = ft_strdup(grp->gr_name);
	else
		info->group = ft_itoa(info->stat.st_gid);
	info->size = info->stat.st_size;
	info->timespec = ls_get_tspc(&info->stat, ls);
	p->s.s.lk = ft_max((ft_intlen((int)info->stat.st_nlink)), p->s.s.lk);
	p->s.s.own = ft_max((ft_strlen(info->owner)), p->s.s.own);
	p->s.s.grp = ft_max((ft_strlen(info->group)), p->s.s.grp);
	p->s.s.min = ft_max(ft_intlen((int)minor(info->stat.st_rdev)), p->s.s.min);
	p->s.s.maj = ft_max(ft_intlen((int)major(info->stat.st_rdev)), p->s.s.maj);
	p->s.s.sz = ft_max(ft_intlen((int)info->size), p->s.s.sz);
}
