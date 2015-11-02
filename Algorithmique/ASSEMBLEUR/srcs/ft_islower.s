# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_islower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/20 10:40:56 by harar             #+#    #+#              #
#    Updated: 2015/03/23 15:58:55 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global _ft_islower

_ft_islower:
	cmp		rdi, 0x61
	jl		Ret
	cmp		rdi, 0x7a
	jg		Ret
	mov		rax, 1
	ret

Ret:
	xor		rax, rax
	ret