# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/20 09:09:32 by harar             #+#    #+#              #
#    Updated: 2015/02/20 10:15:06 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmlxft.a

FLAG = -L/usr/X11/lib -lmlx -lXext -lX11

SRC = 	ft_mlx_draw_line.c \
		ft_mlx_draw_gen.c \
		ft_create_map.c \
		ft_lstnew.c \
		ft_view.c \
		ft_mlx_draw_grid.c \
		ft_launch.c \
		ft_define_color.c \
		ft_print_param.c \
		ft_color.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@echo "\033[35;1m• \033[0mRemoving object files in libmlxft ...\033[55G\c"
	@rm -f $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean: clean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re: fclean all
