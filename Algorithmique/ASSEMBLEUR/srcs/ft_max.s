# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_max.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harar <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/21 15:33:43 by harar             #+#    #+#              #
#    Updated: 2015/03/23 16:00:38 by harar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_max

_ft_max:
	cmp		edi, esi
	jl		Med
	mov		eax, edi
	ret

Med:
	mov		eax, esi
	ret
