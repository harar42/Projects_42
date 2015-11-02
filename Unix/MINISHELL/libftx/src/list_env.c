/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 12:27:10 by harar             #+#    #+#             */
/*   Updated: 2015/05/26 17:21:37 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include "sh1.h"
#include <stdlib.h>

void	ftx_add_elem(t_env **list, char *var_name, char *var)
{
	t_env	*new;
	int		i;
	int		j;
	int		s;

	if ((new = malloc(sizeof(*new))) == NULL)
		ftx_putendl("allocation memoire !");
	s = (var_name != NULL) ? ftx_strlen(var_name) : 0;
	if ((new->data = malloc(sizeof(char) * s + ftx_strlen(var) + 1)) == NULL)
		ftx_putendl("allocation memoire");
	j = -1;
	i = -1;
	while (var_name != NULL && var_name[++i])
		new->data[++j] = var_name[i];
	i = -1;
	if (j != -1)
		new->data[++j] = '=';
	while (var[++i])
		new->data[++j] = var[i];
	new->data[++j] = '\0';
	new->prev = (*list)->prev;
	new->next = (*list);
	(*list)->prev->next = new;
	(*list)->prev = new;
}

t_env	*ftx_retenv(char **env)
{
	t_env	*root;
	int		i;
	char	*path;

	if ((root = malloc(sizeof(*root))) == NULL)
		ftx_putendl("allocation memoire !");
	root->next = root;
	root->prev = root;
	i = -1;
	if (*env != NULL)
	{
		while (env[++i])
			ftx_add_elem(&root, NULL, env[i]);
	}
	else
	{
		path = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Users/harar";
		ftx_putstr_color("Creation d'un nouvel env", CYAN, 1);
		ftx_add_elem(&root, NULL, "HOME=/Users/harar");
		ftx_add_elem(&root, NULL, path);
		ftx_add_elem(&root, NULL, "OLDPWD=/Users/harar/Desktop");
		ftx_add_elem(&root, NULL, "PWD=/Users/harar/");
	}
	return (root);
}

void	ftx_remove_elem(t_env **list, char *value)
{
	t_env	*tmp;

	tmp = (*list)->next;
	while (tmp != (*list) && !ftx_strcmp_sh(tmp->data, value, 1))
		tmp = tmp->next;
	if (tmp != (*list))
	{
		free(tmp->data);
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		free(tmp);
	}
}
