# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 15:20:25 by pasosa-s          #+#    #+#              #
#    Updated: 2019/09/13 14:16:48 by pasosa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

FLAGS = -Wall -Werror -Wextra
FLAGS2 = -framework OpenGL -framework AppKit

INC_DIR = ./inc
INCLUDES = -I ./inc/ -I ./libft/ -I ./minilibx/

LIBFT = ./libft/libft.a
LIBMLX = ./minilibx/libmlx.a

SRCDIR = ./src

SRCS = $(SRCDIR)/main.c \
	   $(SRCDIR)/get_values.c \
	   $(SRCDIR)/mandelbrot_julia.c \
	   $(SRCDIR)/put_pixel.c \
	   $(SRCDIR)/fractals_1.c \
	   $(SRCDIR)/fractals_2.c \
	   $(SRCDIR)/controls_1.c \
	   $(SRCDIR)/controls_2.c \
	   $(SRCDIR)/controls_3.c \
	   $(SRCDIR)/mouse.c \
	   $(SRCDIR)/menu.c \
	   $(SRCDIR)/misc.c

OBJS = $(SRCS:%.c=%.o)

NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	@$(CC) $(INCLUDES) $(LIBFT) $(LIBMLX) $(FLAGS) $(FLAGS2) $(OBJS) -o $@
	@echo "$(GREEN)compilation finished."

$(LIBFT) :
	@make -C libft/ -s
	@echo "$(BLUE)libft.a created."

$(LIBMLX) :
	@make -C minilibx/ -s
	@echo "$(CYAN)libmlx.a created."


clean:
	@echo "$(WHITE)\n     ------- $@ -------\n"
	@rm -f $(OBJS)
	@echo "$(VIOLET)objects deleted"
	@make -C libft/ clean
	@echo "$(BLUE)libft objects deleted."
	@make -C minilibx/ clean
	@echo "$(CYAN)libmlx objects deleted."

fclean: clean
	@echo "$(WHITE)\n     ------- $@ -------\n"
	@rm -f $(NAME)
	@echo "$(WHITE)fractol deleted"
	@make -C libft/ fclean
	@echo "$(BLUE)libft.a deleted."

re: fclean all

.PHONY: all clean fclean re header
