# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/22 16:34:02 by harar             #+#    #+#              #
#    Updated: 2015/03/24 15:58:35 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global _ft_memcpy

_ft_memcpy:
	push		rdi
	mov			rcx, rdx
	rep			movsb
	pop			rdi
	mov			rax, rdi
	ret
