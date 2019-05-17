/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:45:51 by auverneu          #+#    #+#             */
/*   Updated: 2019/05/17 19:37:59 by auverneu         ###   ########.fr       */
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

# define LS_OPTS "1aAcdflrRStuU"

enum ls_flags
{
	F_ONE = 1,
	F_A = 2,
	F_AA = 4,
	F_C = 8,
	F_D = 16,
	F_F = 32,
	F_L = 64,
	F_R = 128,
	F_RR = 256,
	F_S = 512,
	F_T = 1024,
	F_U = 2048,
	F_UU = 4096
};

enum ls_error
{
	ILL_OPT = 1,
	ALLOC_F
};

typedef struct			s_arg
{
	char				*name;
	char				type;
	char				right;
	off_t				size;
	time_t				time;
}						t_arg;

typedef struct			s_stls
{
	char				*ex;
	int					nbe;
	int					flag;
	t_arg				*arg;
}						t_stls;

typedef struct 			s_var
{
	struct stat			st;
	struct dirent		*rep_i;
	DIR					*rep;
	int					tmp;
	int					s_link;
	int					s_size;
	unsigned long		blk;
}						t_var;

typedef struct			s_infols
{
	char				*name;
	char				type;
	char				rights[10];
	unsigned long		link;
	off_t				size;
	char				*owner;
	char				*group;
	time_t				date;
}						t_infols;



t_stls					*ft_ls_info(t_stls *ls, int i);
int						ft_ls_error(int err, char *str);
void					ft_ls_opts(int ac, char **av, t_stls *ls);
int						ft_ls_core(t_stls *ls);
void					ft_ls_sort(t_infols *info, t_stls *ls);
t_stls					*ft_ls_print(t_infols *info, t_stls *ls, t_var *v);
void					ft_ls_list(t_list *mem, t_list *list, char *name);

#endif
