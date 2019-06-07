/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:45:51 by auverneu          #+#    #+#             */
/*   Updated: 2019/06/07 05:38:38 by auverneu         ###   ########.fr       */
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
# include <stdint.h>

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
	F_SS = 512,
	F_T = 1024,
	F_U = 2048,
	F_UU = 4096
};

enum ls_error
{
	ILL_OPT = 1,
	ALLOC_F
};

typedef struct			s_infols
{
	char				*name;
	char				type;
	char				rights[10];
	unsigned long		link;
	char				*owner;
	char				*group;
	off_t				size;
	time_t				date;
}						t_infols;

typedef struct			s_stls
{
	char				*ex;
	int					nbe;
	int					flag;
	t_infols			*arg;
}						t_ls;


typedef struct 			s_var
{
	struct stat			st;
	struct dirent		*rep_i;
	DIR					*rep;
	quad_t				blk;
	union				{
		struct			{
			uint8_t		s_lk:8;
			uint8_t		s_own:8;
			uint8_t		s_grp:8;
			uint8_t		s_sz:8;
			uint8_t		s_min:8;
			uint8_t		s_maj:8;
			uint16_t	tmp:16;
		}				s;
		uint64_t		init;
	}					s;
}						t_var;


t_ls					*ft_ls_info(t_ls *ls, int i);
int						ft_ls_error(int err, char *str);
void					ft_ls_opts(int ac, char **av, t_ls *ls);
int						ft_ls_core(t_ls *ls);
void					ft_ls_sort(t_infols *info, int flag, int nbe);
t_ls					*ft_ls_print(t_infols *info, t_ls *ls, t_var *v, int j);
void					ft_ls_list(t_list **mem, t_list **list, char *name);
time_t					ft_ls_time(struct stat *stat, int flag);
void					ft_ls_fill(t_infols *info, t_ls *ls, char *dir, t_var *v);

#endif
