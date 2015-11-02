# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/01 15:54:01 by harar             #+#    #+#              #
#    Updated: 2015/03/03 16:54:17 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = wolf3d
CFLAGS = -Wall -Werror -Wextra -I ./
LIBFT = libft -lft
LIBMLX = /usr/X11/lib
MLXFLAGS = -lXext -lmlx -lX11
SRCS =  ft_color.c \
		ft_draw.c \
		ft_error.c \
		ft_hook.c \
		ft_init.c \
		ft_main.c \
		ft_parser.c \
		ft_raycast.c \

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C $(LIBFT) fclean
	@make -C $(LIBFT)
	@gcc $(CFLAGS) -c $(SRCS)
	@gcc $(OBJ) -o $(NAME) -L $(LIBFT) -L $(LIBMLX) $(MLXFLAGS)

clean :
	@make -C $(LIBFT) clean
	@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@make -C $(LIBFT) fclean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re : fclean all
