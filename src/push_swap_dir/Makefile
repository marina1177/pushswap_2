NAME = ../push_swap
#.PHONY: all, $(NAME), fclean, re

# ************************************************************************** #
#                           colors                                           #
# ************************************************************************** #

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
AQUA = \033[36m
GREY = \033[37m
UNDERLINE = \033[4m
ESCN = \033[0m
RESET = \033[0m
CLEAR_LINE	:= \033[2K
BEGIN_LINE	:= \033[A
COL_END		:= \033[0m
COL_RED		:= \033[1;31m
COL_GREEN	:= \033[1;32m
COL_YELLOW	:= \033[1;33m
COL_BLUE	:= \033[1;34m
COL_VIOLET	:= \033[1;35m
COL_CYAN	:= \033[1;36m
COL_WHITE	:= \033[1;37m

# ************************************************************************** #
#                           Configuration                                    #
# ************************************************************************** #

CC = gcc
FLAGS= -g #-Wall -Wextra -Werror

LIB = -L ../libft -lft
LIBPATH = ../libft

HEADPATH = ./includes
HEADLIST = main.h
HEAD = -I$(HEADPATH)
INCLUDES = -I$(HEAD)

SRC = main.c carry.c divide_sta.c \
		functions.c median.c rot_functions.c \
		common_1.c
OBJ = $(addprefix $(OBJPATH)/,$(SRC:.c=.o))

#MLIBX = -L  ../minilibx -lmlx -framework OpenGL -framework AppKit
#MLIBXPATH = ../minilibx
OBJPATH = ./objects

# ************************************************************************** #
#                                   Rules                                    #
# ************************************************************************** #

all: $(NAME)

$(NAME):  $(OBJPATH) $(OBJ)
	#@make -C $(LIBPATH)
	#@make -C $(MLIBXPATH)
	gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB) $(MLIBX)

$(OBJPATH):
	mkdir -p $(OBJPATH)

$(OBJPATH)/%.o: %.c
	gcc $(FLAGS) $(HEAD) -c $< -o $@

clean:
	#@make -C $(LIBPATH) clean
	#@make -C $(MLIBXPATH) clean
	/bin/rm -rf $(OBJPATH)

fclean: clean
	#@make -C $(LIBPATH) fclean
	#@make -C $(MLIBXPATH) fclean
	/bin/rm -f $(NAME)

re: fclean all
