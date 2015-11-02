/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 15:19:19 by harar             #+#    #+#             */
/*   Updated: 2015/05/26 15:21:34 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "sh1.h"
#include "libftx.h"

void	ft_setenv(char **cmd, t_env *env2)
{
	if (cmd[1] != NULL && cmd[2] != NULL)
		ftx_setenv_list(env2, cmd[1], cmd[2]);
	else if (cmd[1] != NULL && cmd[2] == NULL)
		ftx_setenv_list(env2, cmd[1], "");
}
