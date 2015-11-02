# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/23 17:35:34 by harar             #+#    #+#              #
#    Updated: 2015/03/24 16:00:21 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	
	global _ft_strdup
	extern _ft_strlen
	extern _malloc

_ft_strdup:

	enter 		16,0
	cmp			rdi, 0x0
	je			Ret
	push		rdi
	call		_ft_strlen
	mov			rdi, rax
	inc			rdi
	mov			rcx, rax
	push		rcx
	call		_malloc
	cmp			rax, 0x0
	je			Ret
	pop			rcx
	pop			rsi
	mov			rdi, rax
	rep			movsb
	mov			byte [rdi + rcx], 0

Ret:
	leave
	ret
