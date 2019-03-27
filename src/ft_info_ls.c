/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:18:39 by auverneu          #+#    #+#             */
/*   Updated: 2018/06/24 17:39:23 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

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
	info->rights[9] = '\0';
}

void		ft_lstend_ls(t_structls *info, struct stat *st_ls, int *pl, int *ps, unsigned long *block)
{
	struct passwd	*user;
	struct group	*group;

	info->nb_link = (unsigned long)st_ls->st_nlink;
	*pl = ft_max((ft_intlen((int)info->nb_link)), *pl);
	user = getpwuid(st_ls->st_uid);
	group = getgrgid(st_ls->st_gid);
	info->owner = user->pw_name;
	info->group = group->gr_name;
	info->size = (unsigned long)st_ls->st_size;
	*ps = ft_max((ft_intlen((int)info->size)), *ps);
	info->date = ft_strdup(ctime(&st_ls->st_mtime));
	*block += st_ls->st_blocks;
}

char			**ft_info_ls(int flags, char *arg)
{
	t_structls		info[2048];
	struct stat		st_ls;
	struct dirent	*rep_info;
	DIR				*rep;
	int				i;
	int				j;
	int				*pl;
	int				*ps;
	char			**dir;
	int				o;
	unsigned long	block;

	o = 0;
	i = 0;
	rep = opendir(arg);
	pl = malloc(sizeof(int));
	ps = malloc(sizeof(int));
	*pl = 0;
	*ps = 0;
	while ((rep_info = readdir(rep)) != NULL)
	{
		info[i].name = ft_strdup(rep_info->d_name);
		lstat(ft_strjoin(arg, info[i].name), &st_ls);
		ft_lstbegin_ls(&info[i], st_ls.st_mode);
		if ((flags & F_L) != 0)
			ft_lstend_ls(&info[i], &st_ls, pl ,ps, &block);
		i++;
	}
	dir = malloc(i * sizeof(char *));
	j = 0;
printf("total %lU\n", block);
	block = 0;
	while (j < i)
	{
		if (!(flags & F_AA) && info[j].name[0] == '.')
			;
		else
		{
		if (info[j].type == 'd' && strcmp(info[j].name, ".") &&
			strcmp(info[j].name, ".."))
			dir[o++] = ft_strjoin(arg, info[j].name);
		if ((flags & F_L) != 0)
		{
			printf("%c%s  %*.lu %s  %s  %*.lu %.12s %s\n", info[j].type, info[j].rights, *pl, info[j].nb_link, info[j].owner, info[j].group, *ps, info[j].size, &info[j].date[4], info[j].name);
			free(info[j].date);
		}
		else
			printf("%s\n", info[j].name);
			free(info[j].name);
		}
		j++;
	}
	closedir(rep);
	free(pl);
	free(ps);
	free(arg);
	return (dir);
}

int		test(int flags, char **av, int i)
{
	char	**dir;
	int		n;

	n = (av[i + 1]) ? 1 : 0;
	while (av[i] != NULL)
	{
		if (strcmp(av[i], ".") && n)
	 		ft_printf("%s:\n", av[i]);
		dir = ft_info_ls(flags, ft_strjoin(av[i], "/"));
		if ((flags & F_RR) && *dir != NULL)
			test(flags, dir++, 0);
		if (av[i + 1])
			printf("\n");
		i++;
	}
	return (0);
}
