# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalpha.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/20 09:31:24 by harar             #+#    #+#              #
#    Updated: 2015/03/23 15:57:44 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_isalpha
	extern	_ft_isupper
	extern	_ft_islower

_ft_isalpha:
	call	_ft_isupper
	cmp		rax, 1
	je		Ret
	call	_ft_islower

Ret:
	ret
