# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 01:53:59 by tde-la-r          #+#    #+#              #
#    Updated: 2024/02/05 02:54:19 by tde-la-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c \
		  parser.c \
		  malloc_map.c \
		  model.c \
		  model_utils.c \
		  line.c \
		  line_utils.c \
		  color_utils.c \
		  hooks_mlx.c \
		  hooks_utils.c \
		  zoom.c \
		  change_colors.c \
		  error_utils.c
SRCS_DIR = sources/
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))

OBJS = $(SRCS:.c=.o)
OBJS_DIR = objects/
OBJS_PATH = $(addprefix $(OBJS_DIR), $(OBJS))

INCLUDES = -I$(INCLUDE_DIR) -I$(LIBX_INCLUDE) -I$(LIBFT_INCLUDE)
INCLUDE_DIR = include/

CC = clang
FLAGS = -Wall -Wextra -Werror -g

LIBDIR = libft/
LIBFT = libft.a
LIBFT_INCLUDE = $(LIBDIR)include/

LIBXDIR = MacroLibX/
LIBX = libmlx.so -lSDL2
LIBX_INCLUDE = $(LIBXDIR)includes/

MATH = -lm

DEFAULT_MAP = maps/42.fdf
SUPP_FILE = $(LIBXDIR)valgrind.supp
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --suppressions=$(SUPP_FILE)

RM = rm -rf

all : macrolibx libft $(NAME)

macrolibx :
	test -d $(LIBXDIR) || git clone https://github.com/seekrs/MacroLibX.git $(LIBXDIR)
	make -C $(LIBXDIR)

libft :
	make -C $(LIBDIR)

$(NAME) : $(OBJS_PATH)
	$(CC) $(OBJS_PATH) -o $(NAME) $(LIBDIR)$(LIBFT) $(LIBXDIR)$(LIBX) $(MATH)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

run : all
	./$(NAME) $(DEFAULT_MAP)

valgrind : all
	valgrind $(VALGRIND_FLAGS) ./$(NAME) $(DEFAULT_MAP)

gdb : all
	gdb --tui $(NAME) -ex 'start $(DEFAULT_MAP)'

clean :
	make clean -C $(LIBDIR)
	make clean -C $(LIBXDIR)
	$(RM) $(OBJS_PATH)

fclean : clean
	$(RM) $(LIBDIR)$(LIBFT)
	$(RM) $(LIBXDIR)
	$(RM) $(NAME)

re : fclean all

.PHONY : all macrolibx libft run valgrind gdb clean fclean re
