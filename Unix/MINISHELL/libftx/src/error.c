/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 12:24:18 by harar             #+#    #+#             */
/*   Updated: 2015/05/18 13:42:21 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include <unistd.h>

int	ftx_err_loc(char *file, int line, char *msg)
{
	(void)line;
	write(2, "Erreur: ", 8);
	ftx_putendl_fd(msg, 2);
	ftx_putendl_fd(file, 2);
	return (1);
}
