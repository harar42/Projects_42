# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcat.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/23 12:35:27 by harar             #+#    #+#              #
#    Updated: 2015/03/24 16:00:04 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global _ft_strcat

_ft_strcat:
	mov		rax, rdi

loop:
	cmp		byte[rdi], 0
	jz		cpy
	inc		rdi
	jmp		loop

cpy:
	cmp		byte[rsi], 0
	jz		end
	movsb
	jmp		cpy

end:
	mov		byte[rdi], 0x0
	ret