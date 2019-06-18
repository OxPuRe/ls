/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:45:51 by auverneu          #+#    #+#             */
/*   Updated: 2019/06/18 01:24:18 by auverneu         ###   ########.fr       */
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

# define LS_OPTS "aAcdflrRStuU"
# define LS_H_OPT	"--help"
# define LS_SW_TIME	(time_t)15778432

# define LS_H_1				"-a\tShow hidden file.\n"
# define LS_H_2		LS_H_1	"-A\tShow hidden file except \".\" and \"..\".\n"
# define LS_H_3		LS_H_2	"-c\tUse time when file status was last changed.\n"
# define LS_H_4		LS_H_3	"-d\tDirectories are listed as plain file.\n"
# define LS_H_5		LS_H_4	"-f\tOutput is not sorted.\n"
# define LS_H_6		LS_H_5	"-l\tDisplay in long format.\n"
# define LS_H_7		LS_H_6	"-r\tReverse the order of the sorting.\n"
# define LS_H_8		LS_H_7	"-R\tRecursive mode.\n"
# define LS_H_9		LS_H_8	"-S\tSort files by size.\n"
# define LS_H_10	LS_H_9	"-t\tSort by time.\n"
# define LS_H_11	LS_H_10	"-u\tUse time of last access.\n"
# define LS_H_12	LS_H_11	"-U\tUse time of file creation.\n"
# define LS_HELP	LS_H_12	"--help\tPrint this help.\n"

enum
{
	LS_POS_ALL = 0,
	LS_POS_ALMOSTALL,
	LS_POS_STATUS,
	LS_POS_DIR,
	LS_POS_NOSORT,
	LS_POS_LONG,
	LS_POS_REVERSE,
	LS_POS_RECURSIVE,
	LS_POS_SIZE,
	LS_POS_TIME,
	LS_POS_ACCESS,
	LS_POS_CREATION,
};

enum
{
	LS_F_ALL = 1U << LS_POS_ALL,
	LS_F_AALL = 1U << LS_POS_ALMOSTALL,
	LS_F_STATUS = 1U << LS_POS_STATUS,
	LS_F_DIR = 1U << LS_POS_DIR,
	LS_F_NOSORT = 1U << LS_POS_NOSORT,
	LS_F_LONG = 1U << LS_POS_LONG,
	LS_F_REVERSE = 1U << LS_POS_REVERSE,
	LS_F_RECURSIVE = 1U << LS_POS_RECURSIVE,
	LS_F_SIZE = 1U << LS_POS_SIZE,
	LS_F_TIME = 1U << LS_POS_TIME,
	LS_F_ACCESS = 1U << LS_POS_ACCESS,
	LS_F_CREATION = 1U << LS_POS_CREATION,
};

enum
{
	LS_E_SUCCESS = 0,
	LS_E_STD,
	LS_E_STD_EXIT,
	LS_E_ARG,
	LS_E_HELP,
};

typedef struct			s_infols
{
	char				*name;
	char				type;
	char				rights[10];
	unsigned long		link;
	char				*owner;
	char				*group;
	union				{
		off_t			size;
		dev_t			dev;
	}					s;
	time_t				date;
}						t_infols;

typedef struct			s_stls
{
	char				*ex;
	int					nbe;
	unsigned int		error;
	unsigned int		flag;
	t_infols			*arg;
}						t_ls;

typedef struct			s_var
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
void					ft_ls_fill(t_infols *info, t_ls *ls, char *dir,
									t_var *v);
void					*ls_exit(int mode, void *arg, t_ls *ls);

#endif
