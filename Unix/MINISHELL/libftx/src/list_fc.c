/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 12:27:21 by harar             #+#    #+#             */
/*   Updated: 2015/05/13 14:36:10 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include <unistd.h>

void	ftx_print_env(t_env *lst, char type)
{
	t_env	*tmp;

	if (!lst)
		return ;
	tmp = lst->next;
	while (tmp != lst)
	{
		ftx_putstr(tmp->data);
		if ((type != 1 && tmp->next != lst) || type == 0)
			ftx_putchar('\n');
		tmp = tmp->next;
	}
}

char	*ftx_find_element(t_env *lst, char *value)
{
	t_env	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst->next;
	while (tmp != lst && !ftx_strcmp_sh(tmp->data, value, 1))
		tmp = tmp->next;
	if (tmp == lst)
		return (NULL);
	return (&tmp->data[ftx_strlen(value) + 1]);
}

void	ftx_setenv_list(t_env *lst, char *var, char *value)
{
	ftx_remove_elem(&lst, var);
	ftx_add_elem(&lst, var, value);
}
