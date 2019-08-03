# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 04:38:21 by auverneu          #+#    #+#              #
#    Updated: 2019/08/03 04:14:27 by auverneu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = clang
INC_PATH = includes
SRC_PATH = srcs
OBJ_PATH = objs
LIBS_NAME = libft
SRC_NAME = main.c\
	ft_ls_core.c\
	ft_ls_info.c\
	ft_ls_print.c\
	ft_ls_sort.c\
	ft_ls_opts.c\
	ft_ls_time.c\
	ft_ls_get_arg.c\
	ft_ls_utils.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIBS = $(foreach LIB, $(LIBS_NAME), $(LIB)/$(LIB).a)
CFLAGS = -Wall -Werror -Wextra -g
CPPFLAGS = -I $(INC_PATH) $(addprefix -I ,$(addsuffix /$(INC_PATH),$(LIBS_NAME)))
CLFLAGS = $(addprefix -L ,$(LIBS_NAME)) $(addprefix -,$(subst ib,,$(LIBS_NAME)))

.PHONY: re all norme clean fclean

all: $(NAME)

$(NAME): $(OBJ) | $(LIBS)
	@printf "\e[32;4m[Linking]:\e[0m %s\n" $@
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(CLFLAGS) $(OBJ) -o $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIBS):
	@printf "\e[34;4m[Making]:\e[0m %s\n" $(patsubst %/,%,$(dir $@))
	@$(MAKE) -C $(dir $@) all

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@printf "\e[35;4m[Cleaning]:\e[0m\n"
	@rm -fv $(OBJ)
	@rm -rf $(OBJ_PATH)
	@$(foreach LIB, $(LIBS_NAME), $(MAKE) -C $(LIB) clean;)

fclean: clean
	@printf "\e[31;4m[Cleaning]:\e[0m\n"
	@rm -fv $(NAME)
	@$(foreach LIB, $(LIBS), rm -f $(LIB);)

re: fclean all

norme:
	@printf "\e[92m"
	@norminette $(SRC)
	@norminette $(INC_PATH)
	@printf "\e[0m\n"
	@$(foreach LIB, $(LIBS_NAME), make -C $(LIB) norme;)
