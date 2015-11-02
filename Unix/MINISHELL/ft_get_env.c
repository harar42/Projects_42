/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 15:17:20 by harar             #+#    #+#             */
/*   Updated: 2015/05/26 17:02:23 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <stdlib.h>

void	ft_env(char **cmd, t_env *env2)
{
	if (cmd[1] == NULL)
	{
		ftx_print_env(env2, 0);
	}
	else if (ft_strcmp(cmd[1], "-i") == 0)
	{
		ftx_remove_elem(&env2, "PATH");
	}
}

char	*ft_getenv(char const *s, char **env)
{
	if (env && s)
		while (*env)
			if (ft_strstr(*env++, s))
				return (*(env - 1) + ft_strpos(*(env - 1), '=') + 1);
	return (0);
}
