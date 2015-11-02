# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/20 09:09:59 by harar             #+#    #+#              #
#    Updated: 2015/02/20 09:10:03 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAG = -g -L/usr/X11/lib -lmlx -lXext -lX11 -L libmlxft -lmlxft -L libft -lft

SRC = fdf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C ./libft/ re
	@make -C ./libmlxft/ re
	@gcc -o $(NAME) $(SRC) $(FLAG)
	@echo "\n\tRUN MY FDF\n\n"

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@make -C libmlxft/ clean
	@echo "\033[35;1m•   \033[0mRemoving object files in fdf ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean
	@make -C libmlxft/ fclean
	@echo "\033[35;1m•   \033[0mRemoving $(NAME) ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re: fclean all
