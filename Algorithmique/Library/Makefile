#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <harar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/09 15:20:26 by harar             #+#    #+#              #
#    Updated: 2014/12/09 15:20:30 by harar            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

FLAG = -Wall -Wextra -Werror

SRC = ft_atoi.c\
	ft_strcmp.c\
	ft_strlen.c\
	ft_strcpy.c\
	ft_isdigit.c\
	ft_isalpha.c\
	ft_isprint.c\
	ft_isascii.c\
	ft_isalnum.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_strcat.c\
	ft_strdup.c\
	ft_strncpy.c\
	ft_strncat.c\
	ft_strncmp.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_strchr.c\
	ft_memmove.c\
	ft_strlcat.c\
	ft_strstr.c\
	ft_memchr.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_putnbr.c\
	ft_putendl.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_memcmp.c\
	ft_strrchr.c\
	ft_memccpy.c\
	ft_strnstr.c\
	ft_strclr.c\
	ft_striter.c\
	ft_strmap.c\
	ft_memdel.c\
	ft_memalloc.c\
	ft_strnew.c\
	ft_strdel.c\
	ft_striteri.c\
	ft_strmapi.c\
	ft_strequ.c\
	ft_strnequ.c\
	ft_putnbr_fd.c\
	ft_strsub.c\
	ft_strtrim.c\
	ft_itoa.c\
	ft_strsplit.c\
	ft_strjoin.c\

SRC1 = ft_atoi.o\
	ft_strcmp.o\
	ft_strlen.o\
	ft_strcpy.o\
	ft_isdigit.o\
	ft_isalpha.o\
	ft_isprint.o\
	ft_isascii.o\
	ft_isalnum.o\
	ft_tolower.o\
	ft_toupper.o\
	ft_strcat.o\
	ft_strdup.o\
	ft_strncpy.o\
	ft_strncat.o\
	ft_strncmp.o\
	ft_memset.o\
	ft_bzero.o\
	ft_memcpy.o\
	ft_strchr.o\
	ft_memmove.o\
	ft_strlcat.o\
	ft_strstr.o\
	ft_memchr.o\
	ft_putchar.o\
	ft_putstr.o\
	ft_putnbr.o\
	ft_putendl.o\
	ft_putchar_fd.o\
	ft_putstr_fd.o\
	ft_putendl_fd.o\
	ft_memcmp.o\
	ft_strrchr.o\
	ft_memccpy.o\
	ft_strnstr.o\
	ft_strclr.o\
	ft_striter.o\
	ft_strmap.o\
	ft_memdel.o\
	ft_memalloc.o\
	ft_strnew.o\
	ft_strdel.o\
	ft_striteri.o\
	ft_strmapi.o\
	ft_strequ.o\
	ft_strnequ.o\
	ft_putnbr_fd.o\
	ft_strsub.o\
	ft_strtrim.o\
	ft_itoa.o\
	ft_strsplit.o\
	ft_strjoin.o\

all: $(NAME)

$(NAME) :
	@echo "Processing files..."
	@gcc $(FLAG) -c $(SRC)
	@ar rc $(NAME) $(SRC1)
	@ranlib $(NAME)
	@echo "$(NAME) has been created !"

clean:
	@rm -rf $(SRC1)
	@echo "objects files have been removed !"
fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) has been removed !"

re: fclean all