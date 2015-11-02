/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 15:24:41 by harar             #+#    #+#             */
/*   Updated: 2015/05/26 15:34:42 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "sh1.h"
#include <stdlib.h>
#include "libftx.h"

int	toto(char **ret, char **cmd, char **env)
{
	pid_t	father;
	int		status2;
	char	*path;

	path = ft_check_path(ret, cmd[0]);
	if (path == NULL)
		return (0);
	if ((father = fork()) == -1)
		return (-1);
	if (father == 0)
	{
		signal(SIGINT, SIG_DFL);
		execve(path, cmd, env);
		exit(EXIT_FAILURE);
	}
	else if (father > 0)
	{
		waitpid(father, &status2, 0);
		free(path);
	}
	return (0);
}

int	main(void)
{
	extern char	**environ;
	char		**cmd;
	char		**ret;
	t_env		*env2;

	env2 = ftx_retenv(environ);
	signal(SIGINT, SIG_IGN);
	while (42)
	{
		ft_printp(env2);
		cmd = ft_ret_getnext();
		if (cmd == NULL || cmd[0] == NULL)
			continue;
		ret = ft_searchpath(ftx_find_element(env2, "PATH"));
		if (ft_check_cmd(cmd[0]) == 1)
			ft_exec(cmd, env2);
		else
		{
			if (toto(ret, cmd, ft_conv_lst(env2)) == -1)
				return (-1);
		}
	}
	return (0);
}
