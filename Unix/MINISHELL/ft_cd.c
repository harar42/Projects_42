/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 09:31:45 by harar             #+#    #+#             */
/*   Updated: 2015/05/26 16:58:49 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <unistd.h>
#include <stdlib.h>

static char	*ft_get_path(char **tab, t_env *env)
{
	char	*tmp;

	tmp = NULL;
	if (tab[1] == NULL || tab[1][0] == '~')
	{
		tmp = ftx_find_element(env, "HOME");
		if (tmp == NULL)
			ft_putendl("Can't find a HOME, please set it");
	}
	else if (tab[1] == NULL || tab[1][0] == '-')
	{
		tmp = ftx_find_element(env, "OLDPWD");
		if (tmp == NULL)
			ft_putendl("Can't find a OLDPWD, please set it");
	}
	else
	{
		if (access(tab[1], X_OK) == -1)
			ft_putendl(": No such file or directory");
		else
			tmp = tab[1];
	}
	return (tmp);
}

void		ft_cd(char **tab, t_env *env)
{
	char	*tmp;
	char	*path;

	path = ft_get_path(tab, env);
	if (path == NULL)
		return ;
	tmp = getcwd(NULL, 0);
	if (chdir(path) == -1)
		ft_putendl("Permission denied");
	else
	{
		if (ftx_find_element(env, "PWD"))
			ftx_setenv_list(env, "OLDPWD", ftx_find_element(env, "PWD"));
		else
			ftx_setenv_list(env, "OLDPWD", tmp);
		ftx_setenv_list(env, "PWD", getcwd(NULL, 0));
	}
}
