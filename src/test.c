/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:18:39 by auverneu          #+#    #+#             */
/*   Updated: 2018/05/13 18:27:10 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_type_ls(char *info, mode_t st_mode)
{
	    if (st_mode & S_IFREG)
        sprintf(info, "-");
    else if (st_mode & S_IFDIR)
        sprintf(info, "d");
    else if (st_mode & S_IFLNK)
        sprintf(info, "l");
    else if (st_mode & S_IFIFO)
        sprintf(info, "p");
    else if (st_mode & S_IFSOCK)
        sprintf(info, "s");
    else if (st_mode & S_IFCHR)
        sprintf(info, "c");
    else if (st_mode & S_IFBLK)
        sprintf(info, "b");
};

void	ft_rights_ls(char *info, mode_t st_mode)
{
	(st_mode & S_IRUSR) ? sprintf(info++, "r") : sprintf(info++, "-");
    (st_mode & S_IWUSR) ? sprintf(info++, "w") : sprintf(info++, "-");
    (st_mode & S_IXUSR) ? sprintf(info++, "x") : sprintf(info++, "-");
    (st_mode & S_IRGRP) ? sprintf(info++, "r") : sprintf(info++, "-");
    (st_mode & S_IWGRP) ? sprintf(info++, "w") : sprintf(info++, "-");
    (st_mode & S_IXGRP) ? sprintf(info++, "x") : sprintf(info++, "-");
    (st_mode & S_IROTH) ? sprintf(info++, "r") : sprintf(info++, "-");
    (st_mode & S_IWOTH) ? sprintf(info++, "w") : sprintf(info++, "-");
    (st_mode & S_IXOTH) ? sprintf(info, "x") : sprintf(info, "-");

};

int		ft_info_ls(char **av)
{
	struct stat	st_ls;
	char		*info;

 	info = (char *)malloc(11 * sizeof(char));
	stat(av[1], &st_ls);
	ft_type_ls(info, st_ls.st_mode);
	ft_rights_ls(&info[1], st_ls.st_mode);
	printf("%s\n", info);
	return (0);
}
