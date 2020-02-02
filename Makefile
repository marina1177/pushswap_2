# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/26 16:23:46 by bcharity          #+#    #+#              #
#    Updated: 2020/02/02 12:40:32 by bcharity         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_C = checker
NAME_P = push_swap

FLAGS = -Wall -Wextra -Werror
LIB_DIR = libft/
HEADER_DIR = includes/

LIB = -L ./libft -lft
LIBPATH = libft/
################ COMMON FILES ########################
SRC_COM =		common_1.c \
				common_2.c \
				functions.c \
				rot_functions.c

SRC_DIR_COM =	src/common/
#################### CHEKER FILES ####################
SRC_C = checker.c

SRC_DIR_C = src/checker_dir/
######################################################

#################### PUSH_SWAP FILES #################
SRC_P =			 main.c \
				remind_1.c \
				remind_2.c \
				sorting_1.c \
				sorting_2.c \
				median_1.c \
				median_2.c

SRC_DIR_P = src/push_swap_dir/
######################################################

OBJ_COM = $(patsubst %.c,%.o,$(SRC_COM))
OBJ_C = $(patsubst %.c, %.o, $(SRC_C))
OBJ_P = $(patsubst %.c, %.o, $(SRC_P))

OBJ_DIR = obj/
OBJ_DIR_COM = $(OBJ_DIR)o_common/
OBJ_DIR_C = obj/o_checker/
OBJ_DIR_P = obj/o_push_swap/

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR_COM)%.o: $(SRC_DIR_COM)%.c
	@mkdir -p $(OBJ_DIR_COM)
	@gcc -c $< -o $@ -I $(HEADER_DIR)

$(OBJ_DIR_C)%.o: $(SRC_DIR_C)%.c
		@mkdir -p $(OBJ_DIR_C)
		@gcc -c $< -o $@ -I $(HEADER_DIR)

$(OBJ_DIR_P)%.o: $(SRC_DIR_P)%.c
		@mkdir -p $(OBJ_DIR_P)
		@gcc -c $< -o $@ -I $(HEADER_DIR)

$(NAME): $(addprefix $(OBJ_DIR_COM),$(OBJ_COM)) $(addprefix $(OBJ_DIR_C),$(OBJ_C)) $(addprefix $(OBJ_DIR_P),$(OBJ_P))
	@make -C $(LIBPATH)
	@gcc $(addprefix $(OBJ_DIR_COM),$(OBJ_COM)) $(addprefix $(OBJ_DIR_C),$(OBJ_C)) $(LIB)  -o $(NAME_C)
	@gcc $(addprefix $(OBJ_DIR_COM),$(OBJ_COM)) $(addprefix $(OBJ_DIR_P),$(OBJ_P)) $(LIB) -o $(NAME_P)


clean:
		@make -C $(LIBPATH) clean
		@rm -Rf $(OBJ_DIR)

fclean: clean
		@make -C $(LIBPATH) fclean
		@rm -f $(NAME_P) $(NAME_C)

re: fclean all
