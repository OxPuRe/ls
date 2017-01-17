/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:59:29 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/31 01:02:29 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <wchar.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define GNL_BUFF_SIZE 32

# define FT_XDIGIT "0123456789abcdef"

# define ULLONG		unsigned long long
# define ULONG		unsigned long
# define LLONG		long long
# define UCHAR		unsigned char
# define UINT		unsigned int
# define USHRT		unsigned short

# define F_HASH		prtf->flag[0]
# define F_ZERO		prtf->flag[1]
# define F_NBPREC	prtf->flag[11]
# define F_PREC		prtf->flag[12]
# define F_WIDTH	prtf->flag[14]

# define FT_MASK_B		0b10000000
# define FT_WC_MASK		"\x00\xC0\xE0\xF0"

/*
** \x00 = 0b00000000
** \xC0 = 0b11000000
** \xE0 = 0b11100000
** \xF0 = 0b11110000
*/

typedef struct		s_fd
{
	char			*strt;
	char			*buff;
	int				fd;
	struct s_fd		*next;
}					t_fd;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_strc
{
	int				fd;
	int				ret;
	int				pos;
	char			*buf;
	char			*rest;
	char			*tmp;
	struct s_strc	*next;
}					t_strc;

typedef struct		s_file
{
	va_list			ap;
	char			*form;
	char			*i;
	char			*mem;
	int				print;
	int				flag[16];
}					t_file;

char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int c);
char				*ft_lltoa_base(long long value, int base);
char				*ft_lltoa_base(long long value, int base);
char				*ft_lltoa(long long n);
char				*ft_strcasestr(const char *s1, const char *s2);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strtrimc(char const *s, char c);
char				*ft_strupper(char *str);
char				*ft_ulltoa_base(uintmax_t n, int base);
int					ft_atoi(char *str);
int					ft_gnl(int const fd, char **line);
int					ft_intlen(int n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isblank(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_llonglen_base(long long n, int base);
int					ft_llonglen(long long n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_printf(const char *format, ...);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_ullonglen_base(unsigned long long n, int base);
int					ft_wctomb(char *s, wchar_t w);
int					*ft_ssplitnb(char const *s);
size_t				ft_countwords(char const *s, char c);
size_t				ft_ilen_base(unsigned int x, unsigned int base);
size_t				ft_nbinstr(char const *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
size_t				ft_wclen(wchar_t w);
size_t				ft_wcstrlen(wchar_t *w);
t_file				*create(char *format);
t_list				*ft_lstdup(t_list *lst);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
unsigned int		ft_abs(int nb);
unsigned int		ft_atoi_base(char *str, int base);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				display_o(t_file *prtf, int *i);
void				display_prec(t_file *prtf, int i, int j);
void				display_t(t_file *prtf, int i, int j);
void				flag_prec(t_file *prtf);
void				flag_sd(t_file *prtf);
void				flag_sharp(t_file *prtf);
void				flag_star(t_file *prtf);
void				flag(t_file *prtf);
void				ft_bzero(void *s, size_t n);
void				ft_free_s(t_file *prtf);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_memdel(void **ap);
void				ft_print(t_file *prtf);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar_prtf(char c, t_file *prtf);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_ll(long long n);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_reverse(char *str);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				parse_sd(t_file *prtf);
void				parse(t_file *prtf);
void				prtf_c_up(t_file *prtf);
void				prtf_c(t_file *prtf);
void				prtf_di(t_file *prtf);
void				prtf_oux(t_file *prtf);
void				prtf_p(t_file *prtf);
void				prtf_percent(t_file *prtf);
void				prtf_s_up(t_file *prtf, size_t k);
void				prtf_s(t_file *prtf);
void				reset_flag(t_file *prtf);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
void				*ft_memset_int(void *b, int c, size_t len);

#endif
