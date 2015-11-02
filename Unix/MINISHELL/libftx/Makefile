# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <harar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/19 11:11:25 by glafitte          #+#    #+#              #
#    Updated: 2015/05/18 13:37:40 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libftx.a
CFLAGS = -Wall -Wextra -Werror -g -I ../include/
CC = gcc
SRCS =	src/ft_putcolor.c \
		src/ft_strlen.c \
		\
		src/ft_putchar.c \
		src/ft_putchar_fd.c \
		src/ft_putstr.c \
		src/ft_putendl.c \
		src/ft_putendl_fd.c \
		\
		src/env_fc.c \
		src/ft_strcmpsh.c \
		src/list_env.c \
		src/list_fc.c \
		src/ft_conv_lst.c \
		src/ft_strdup.c \
		src/error.c
		\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "\033[35;1m• \033[0mCompilation de $(NAME) ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

OBJ : $(OBJ)
	$(CC) $(CFLAGS) $< -c $(SRCS)

clean :
	@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re : fclean all
