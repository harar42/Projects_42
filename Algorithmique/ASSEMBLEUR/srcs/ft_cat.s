# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_cat.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/23 15:31:04 by harar             #+#    #+#              #
#    Updated: 2015/03/23 15:56:53 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_cat
	section .text

_ft_cat:
	cmp				rdi, 0
	jl				Ret
	push			rdi

Med:
	pop				rdi
	lea				rsi, [rel buffer]
	mov				rdx, 0x1000
	mov				rax, 0x2000003
	syscall
	jc				Ret
	cmp				rax, 0x0
	je				Ret
	push			rdi
	mov				rdi, 0x1
	mov				rdx, rax
	mov				rax, 0x2000004
	syscall
	jc				Ret
	jmp				Med

Ret:
	ret

section .bss
buffer:		resb 0x1000
