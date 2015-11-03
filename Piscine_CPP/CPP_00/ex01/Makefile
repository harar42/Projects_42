# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <harar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/03 11:53:16 by harar             #+#    #+#              #
#    Updated: 2015/11/03 11:56:59 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRC_PATH = ./
SRC_NAME =  phonebook.cpp Contact.class.cpp
OBJ_NAME = $(SRC_NAME:.cpp=.o)
INC_PATH = -I .
CC = clang++
CFLAGS = -Werror -Wall -Wextra
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

all: $(NAME)

$(NAME):
	$(CC) -c $(INC_PATH) $(SRC)
	$(CC) -o $(NAME) $(OBJ_NAME)

clean:
	rm -f $(OBJ_NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all