/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 13:56:39 by harar             #+#    #+#             */
/*   Updated: 2014/12/09 11:26:11 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putstr_fd(char const *s, int fd)
{
	int		i;
	char	*ptrs;

	i = 0;
	ptrs = (char*)s;
	while (ptrs[i] != '\0')
		ft_putchar_fd(ptrs[i++], fd);
}
