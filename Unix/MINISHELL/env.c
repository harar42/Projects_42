/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 10:53:22 by harar             #+#    #+#             */
/*   Updated: 2015/05/26 17:12:21 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "sh1.h"
#include "libftx.h"

char		*ft_join(char const *s1, char const *s2)
{
	char	*tmp;
	char	*tmp2;

	if (s1 && s2)
	{
		tmp = ft_strjoin(s1, "/");
		tmp2 = ft_strjoin(tmp, s2);
		return (tmp2);
	}
	else
		return (NULL);
}

void		ft_printp(t_env *env2)
{
	char	*tmp;

	tmp = ft_prompt(ftx_find_element(env2, "PWD"));
	ft_putstr(C_RED);
	ft_putstr(C_BOLD);
	ft_putchar('(');
	ft_putstr(C_CYAN);
	ft_putstr(C_BOLD);
	if (tmp)
		ft_putstr(tmp);
	ft_putstr(C_RED);
	ft_putstr(C_RED);
	ft_putstr(C_BOLD);
	ft_putchar(')');
	ft_putstr(C_NONE);
	ft_putchar(' ');
	ft_putstr(C_CYAN);
	ft_strdel(&tmp);
}

char		*ft_check_path(char **ret, char *cmd)
{
	int		i;
	char	*path;

	i = -1;
	if (ft_strchr(cmd, '/') != NULL || ft_strnstr(cmd, "./", 2) != NULL)
	{
		if (access(path = cmd, X_OK) == 0)
			return (path);
		else
			ft_putendl("Commande introuvable");
	}
	else if (ret)
		while (ret[++i])
		{
			path = ft_join(ret[i], cmd);
			if (access (path, X_OK) == 0)
				return (path);
			free(path);
		}
	if (!ret || ret[i] == '\0')
		ft_putendl("Commande introuvable");
	return (NULL);
}

int			ft_check_cmd(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "setenv") == 0)
		return (1);
	else if (ft_strcmp(cmd, "unsetenv") == 0)
		return (1);
	else if (ft_strcmp(cmd, "env") == 0)
		return (1);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	else
		return (0);
}

void		ft_exec(char **cmd, t_env *env2)
{
	if (ft_strcmp (cmd[0], "cd") == 0)
		ft_cd(cmd, env2);
	else if (ft_strcmp (cmd[0], "setenv") == 0)
		ft_setenv(cmd, env2);
	else if (ft_strcmp (cmd[0], "unsetenv") == 0)
		ft_unsetenv(cmd, env2);
	else if (ft_strcmp (cmd[0], "env") == 0)
		ft_env(cmd, env2);
	else if (ft_strcmp (cmd[0], "exit") == 0)
		exit(EXIT_SUCCESS);
}
