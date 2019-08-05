/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:45:51 by auverneu          #+#    #+#             */
/*   Updated: 2019/08/05 08:22:09 by auverneu         ###   ########.fr       */
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
# define LS_H_OPT	"--help"
# define LS_SL_BUFF	(size_t)1024
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
	LS_POS_LINE = 0,
	LS_POS_ALL,
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
	LS_F_LINE = 1U << LS_POS_LINE,
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

typedef struct			s_info
{
	char				name[NAME_MAX];
	struct stat			stat;
	struct timespec		timespec;
	off_t				size;
	char				*owner;
	char				*group;
	char				mode[11];
}						t_info;

typedef struct			s_stls
{
	char				*ex;
	size_t				nbe;
	unsigned int		flag:13;
	char				aff_dir:1;
	char				**path;
}						t_ls;

typedef struct			s_var
{
	DIR					*op;
	struct dirent		*rd;
	t_info				elem;
}						t_var;

typedef struct			s_av
{
	struct stat 		stat;
	union				{
		struct			{
			uint8_t		f:8;
			uint8_t		d:8;
			uint16_t	e:16;
		}				n;
		uint32_t		init;
	}					n;
}						t_av;

typedef struct			s_print
{
	size_t				nbe;
	quad_t				block;
	union				{
		struct			{
			uint16_t	own:16;
			uint16_t	grp:16;
			uint8_t		lk:8;
			uint8_t		sz:8;
			uint8_t		min:8;
			uint8_t		maj:8;
		}				s;
		uint64_t		init;
	}					s;
}						t_print;

char					*ls_get_tmp(char *name, char *dir, t_ls *ls);
char					*ls_print_link(char *name, int mode, t_ls *ls);
int						ls_core(t_ls *ls);
int						ls_error(int err, char *str);
void					*ls_exit(int mode, void *arg, t_ls *ls);
void					*ls_malloc(size_t size, t_ls *ls);
void					ls_del(void *content, size_t size);
void					ls_display(t_info *info, t_print *print, t_ls *ls,
									t_ls *lsr);
void					ls_info(t_info *info, t_print *p, t_ls *ls);
void					ls_list(t_list **mem, t_list **list, t_info *info);
void					ls_opts(int ac, char **av, t_ls *ls);
void					ls_recup_arg(char **av, t_ls *ls);
void					ls_sort(t_info *info, int flag, int nbe);

#endif
