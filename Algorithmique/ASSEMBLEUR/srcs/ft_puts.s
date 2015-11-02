# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_puts.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/23 15:34:56 by harar             #+#    #+#              #
#    Updated: 2015/03/24 15:59:49 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global	_ft_puts
extern	_ft_strlen

_ft_puts:
	push	rdi
	
	call	_ft_strlen

	mov		rdx, rax
	pop		rsi
	mov		rdi, 1
	mov		rax, 0x2000004
	
	syscall

	mov		rdx, 1
	mov		rdi, 1
	push	10
	mov		rsi, rsp
	mov		rax, 0x2000004

	syscall

	pop		rax
	ret


	
