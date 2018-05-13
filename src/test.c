/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:18:39 by auverneu          #+#    #+#             */
/*   Updated: 2018/05/13 17:10:57 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*ft_rights(char *rights, mode_t info)
{
	char	*ret;

	ret = rights;
	(info & S_IRUSR) ? sprintf(rights, "r") : sprintf(rights, "-");
    (info & S_IWUSR) ? sprintf(rights++, "w") : sprintf(rights++, "-");
    (info & S_IXUSR) ? sprintf(rights++, "x") : sprintf(rights++, "-");
    (info & S_IRGRP) ? sprintf(rights++, "r") : sprintf(rights++, "-");
    (info & S_IWGRP) ? sprintf(rights++, "w") : sprintf(rights++, "-");
    (info & S_IXGRP) ? sprintf(rights++, "x") : sprintf(rights++, "-");
    (info & S_IROTH) ? sprintf(rights++, "r") : sprintf(rights++, "-");
    (info & S_IWOTH) ? sprintf(rights++, "w") : sprintf(rights++, "-");
    (info & S_IXOTH) ? sprintf(rights++, "x") : sprintf(rights++, "-");
	sprintf(rights++, "\0");
	return (ret);
};

int		test(char **av)
{
	struct stat	st_ls;
	char		rights[11];

	stat(av[1], &st_ls);
	printf("%s\n", ft_rights(rights, st_ls.st_mode));
	return (0);
}
