/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:18:39 by auverneu          #+#    #+#             */
/*   Updated: 2018/05/15 12:15:18 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*ft_type_ls(char *info, mode_t st_mode)
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
	return (info+1);
};

char	*ft_rights_ls(char *info, mode_t st_mode)
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
	return (info);

};

int		ft_info_ls(char **av)
{
	struct stat	st_ls;
	char		*info;
	char		*ret;

 	info = (char *)malloc(11 * sizeof(char));
	ret = info;
	stat(av[1], &st_ls);
	info = ft_type_ls(info, st_ls.st_mode);
	info = ft_rights_ls(info, st_ls.st_mode);
	//sprintf(info++, )
	printf("%s\n", ret);
	return (0);
}
