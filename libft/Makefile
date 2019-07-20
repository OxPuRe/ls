# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 04:38:21 by auverneu          #+#    #+#              #
#    Updated: 2019/07/20 19:51:52 by auverneu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = clang
INC_PATH = includes
SRC_PATH = srcs
OBJ_PATH = objs
SRC_NAME = flag_aff.c\
	flag.c\
	ft_atoi.c\
	ft_atoi_base.c\
	ft_abs.c\
	ft_bzero.c\
	ft_llonglen_base.c\
	ft_llonglen.c\
	ft_lltoa_base.c\
	ft_lltoa.c\
	ft_countwords.c\
	ft_intlen.c\
	ft_ilen_base.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isblank.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_lltoa_base.c\
	ft_lstadd.c\
	ft_lstdel.c\
	ft_lstdelone.c\
	ft_lstdup.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_lstnew.c\
	ft_memalloc.c\
	ft_memccpy.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memdel.c\
	ft_memmove.c\
	ft_memset.c\
	ft_print.c\
	ft_printf.c\
	ft_putchar_fd.c\
	ft_putchar.c\
	ft_putendl_fd.c\
	ft_putendl.c\
	ft_putnbr_fd.c\
	ft_putnbr_ll.c\
	ft_putnbr.c\
	ft_putstr_fd.c\
	ft_putstr.c\
	ft_reverse.c\
	ft_revert.c\
	ft_strcasestr.c\
	ft_strcat.c\
	ft_strchr.c\
	ft_strclr.c\
	ft_strcmp.c\
	ft_strcpy.c\
	ft_strdel.c\
	ft_strdup.c\
	ft_strequ.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strxjoin.c\
	ft_strlcat.c\
	ft_strlen.c\
	ft_strnlen.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strncat.c\
	ft_strncmp.c\
	ft_strncpy.c\
	ft_strnequ.c\
	ft_strnew.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strsplit.c\
	ft_strstr.c\
	ft_strsub.c\
	ft_strtrim.c\
	ft_strtrimc.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_ullonglen_base.c\
	ft_ulltoa_base.c\
	ft_wclen.c\
	ft_wcstrlen.c\
	ft_wctomb.c\
	parsing.c\
	prtf_cs.c\
	prtf_csup.c\
	prtf_di.c\
	prtf_oux.c\
	prtf_tools.c\
	ft_gnl.c\
	ft_nbinstr.c\
	ft_max.c\
	ft_min.c\
	ft_memset_int.c\
	ft_putchar_prtf.c\
	ft_strupper.c\
	ft_memswap.c\
	ft_qsort.c\
	ft_pathjoin.c\
	ft_lstend.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I $(INC_PATH)

.PHONY: re all norme clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@printf "%s\n" $@
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@printf "\e[31;4m[Cleaning]:\e[0m\n"
	@rm -f $(OBJ)
	@rm -rvf $(OBJ_PATH)

fclean: clean
	@rm -fv $(NAME)

re: fclean all

norme:
	@printf "\e[92m"
	@norminette $(SRC)
	@norminette $(INC_PATH)
	@printf "\e[0m\n"
