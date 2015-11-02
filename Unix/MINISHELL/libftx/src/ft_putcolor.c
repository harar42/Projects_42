/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 12:25:41 by harar             #+#    #+#             */
/*   Updated: 2015/05/11 12:25:45 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

void	ftx_putstr_color(const char *str, char *color, int i)
{
	ftx_putstr(color);
	ftx_putstr(str);
	ftx_putstr("\033[0m");
	if (i == 1)
		ftx_putchar('\n');
}
