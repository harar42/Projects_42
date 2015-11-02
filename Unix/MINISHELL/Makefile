# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <harar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/04 09:32:01 by harar             #+#    #+#              #
#    Updated: 2015/05/26 15:37:37 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = ft_sh1
CFLAGS = -Wall -Werror -Wextra -g -I include/
LIBFT = libft/
LIBFTX = libftx/
CC = gcc
SRCS =	main.c \
		ft_builts.c \
		ft_cd.c \
		ft_get_env.c \
		ft_unsetenv.c \
		ft_setenv.c\
		env.c
		\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@make -C $(LIBFTX)
	$(CC) $(OBJ) -o $(NAME) -L $(LIBFT) -lft -L $(LIBFTX) -lftx
	@echo "\033[35;1m• \033[0mCompilation de $(NAME) ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

OBJ : $(OBJ)
	$(CC) $(CFLAGS) $< -c $(SRCS)

clean :
	@make -C $(LIBFT) clean
	@make -C $(LIBFTX) clean
	@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@make -C $(LIBFT) fclean
	@make -C $(LIBFTX) fclean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re : fclean all
