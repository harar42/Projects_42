# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_tolower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/22 15:15:15 by harar             #+#    #+#              #
#    Updated: 2015/03/24 16:01:07 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_tolower
	extern	_ft_isupper

_ft_tolower:
	call	_ft_isupper
	cmp		rax, 0
	je		Lret
	mov		rax, rdi
	add		rax, 0x20
	ret

Lret:
	mov		rax, rdi
	ret
