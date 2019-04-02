# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 04:38:21 by auverneu          #+#    #+#              #
#    Updated: 2018/06/06 19:03:30 by auverneu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = clang
INC_PATH = include
SRC_PATH = src
OBJ_PATH = obj
LIBS_NAME = libft
SRC_NAME = main.c\
	ft_info_ls.c
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
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $(NAME) $(CLFLAGS)

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
	@printf "\e[31m"
	@norminette $(SRC) | grep -Eiw -B1 "Warning|Error" || true
	@norminette $(INC_PATH) | grep -Eiw -B1 "Warning|Error" || true
	@printf "\e[0m\n"
	@$(foreach LIB, $(LIBS_NAME), make -C $(LIB) norme;)
