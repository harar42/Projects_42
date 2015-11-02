# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_toupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/23 15:36:26 by harar             #+#    #+#              #
#    Updated: 2015/03/24 16:00:36 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_toupper
	extern	_ft_islower

_ft_toupper:
	call	_ft_islower
	cmp		rax, 0
	je		Lret
	mov		rax, rdi
	sub		rax, 0x20
	ret

Lret:
	mov		rax, rdi
	ret
