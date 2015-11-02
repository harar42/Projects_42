# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalnum.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/20 09:25:14 by harar             #+#    #+#              #
#    Updated: 2015/03/23 15:57:28 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_isalnum
	extern	_ft_isalpha
	extern	_ft_isdigit

_ft_isalnum:
	call	_ft_isdigit
	cmp		rax, 1
	je		Ret
	call	_ft_isalpha

Ret:
	ret
