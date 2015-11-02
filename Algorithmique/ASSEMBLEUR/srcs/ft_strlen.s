# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/22 15:36:03 by harar             #+#    #+#              #
#    Updated: 2015/03/24 16:01:22 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_strlen

_ft_strlen:
	cmp		rdi, 0x0
	je		Ret
	xor		rcx, rcx
	not		rcx
	cld
	xor		rax, rax
	repnz	scasb
	not		rcx
	dec		rcx
	mov		rax, rcx
	ret

Ret:
	xor		rax, rax
	ret
