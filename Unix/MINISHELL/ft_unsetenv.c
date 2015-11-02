/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 15:22:35 by harar             #+#    #+#             */
/*   Updated: 2015/05/26 15:24:01 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "sh1.h"
#include "libftx.h"

void	ft_unsetenv(char **cmd, t_env *env2)
{
	if (cmd[1] == NULL)
	{
		return ;
	}
	else if (cmd[1] != NULL)
	{
		ftx_remove_elem(&env2, cmd[1]);
	}
}
