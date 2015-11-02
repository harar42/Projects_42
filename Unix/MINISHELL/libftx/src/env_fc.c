/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 12:23:57 by harar             #+#    #+#             */
/*   Updated: 2015/05/11 12:24:02 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include <stdlib.h>

char	*ftx_getenv(t_env *env, char *var_name)
{
	char	*var;

	var = ftx_find_element(env, var_name);
	return (var);
}

int		ftx_free_env(t_env *list)
{
	t_env	*tmp;
	t_env	*next;

	tmp = list->next;
	while (tmp != list)
	{
		next = tmp->next;
		free(tmp->data);
		free(tmp);
		tmp = next;
	}
	free(list);
	return (1);
}
