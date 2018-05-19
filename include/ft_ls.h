/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:45:51 by auverneu          #+#    #+#             */
/*   Updated: 2018/05/19 19:29:02 by auverneu         ###   ########.fr       */
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

# define LS_OPTS "1aAcCdflrRtuUs"

enum ls_flags
{
	F_ONE = 1,
	F_A = 2,
	F_AA = 4,
	F_C = 8,
	F_CC = 16,
	F_D = 32,
	F_F = 64,
	F_L = 128,
	F_R = 256,
	F_RR = 512,
	F_T = 1024,
	F_U = 2048,
	F_UU = 4096,
	F_S = 8192
};

enum ls_error
{
	ILL_OPT = 1
};

typedef struct				s_reg_ls
{
	char					type;
	char					*name;
}							t_reg_ls;

typedef struct				s_listls
{
	char					type;
	char					*rights;
	char					*owner;
	char					*group;
	unsigned long			nb_link;
	unsigned long			size;
	int						size_len;
	char					*date;
	char					*name;
}							t_listls;

int							ft_infolst_ls(int *prc_size, char *name, int flags);
t_listls					*ft_alloc_listls(void);
#endif
