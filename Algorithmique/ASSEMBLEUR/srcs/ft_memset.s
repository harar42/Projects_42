# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memset.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/22 10:34:15 by harar             #+#    #+#              #
#    Updated: 2015/03/24 15:58:31 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global _ft_memset

_ft_memset:
	push		rdi
	mov			rax, rsi
	mov			rcx, rdx
	rep			stosb
	pop			rdi
	mov			rax, rdi
	ret