/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:45:51 by auverneu          #+#    #+#             */
/*   Updated: 2018/05/15 19:19:18 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/ioctl.h>
# include <sys/xattr.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <stdlib.h>
# include <libft.h>
# include <limits.h>
# include <pwd.h>
# include <grp.h>

enum ls_opts
{
	ONE = 1, A = 2, AA = 4, C = 8, CC = 16, D = 32, F = 64, L = 128, R = 256,
	S = 512, T = 1024, U = 2048, UU = 4096
};

typedef struct				s_info
{
	unsigned int	flags;
}					t_info;

typedef struct				s_listls
{
	char			type;
	char			*rights;
	char			*owner;
	char			*group;
	unsigned long	nb_link;
	unsigned long	size;
	char			*date;
}					t_listls;

//int		ft_info_ls(char **av);
#endif
