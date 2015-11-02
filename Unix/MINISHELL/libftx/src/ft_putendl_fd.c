/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 12:26:08 by harar             #+#    #+#             */
/*   Updated: 2015/05/11 12:26:12 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include <unistd.h>

void	ftx_putendl_fd(char const *s, int fd)
{
	write(fd, s, ftx_strlen(s));
	ftx_putchar_fd('\n', fd);
}
