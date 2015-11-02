/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:57:06 by harar             #+#    #+#             */
/*   Updated: 2015/05/26 17:12:41 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "sh1.h"
#include "libftx.h"

char		*ft_cleanstr(char *s)
{
	if (ft_strstr(s, "\t"))
		s = ft_strrep(s, "\t", " ", 1);
	if (ft_strstr(s, "  "))
		s = ft_strrep(s, "  ", " ", 1);
	return (s);
}

char		**ft_ret_getnext(void)
{
	char	**cmd;
	char	*s;

	while (get_next_line(0, &s) > 0)
	{
		if (*s)
			cmd = (ft_strsplit(ft_cleanstr(s), ' '));
		else
			cmd = NULL;
		return (cmd);
	}
	exit(0);
	return (NULL);
}

char		**ft_searchpath(char *s)
{
	char	**path;

	if (!s)
		return (NULL);
	path = ft_strsplit(s, ':');
	return (path);
}

char		*ft_prompt(char *path)
{
	int		i;
	char	**ret;
	char	*tmp;

	if (path == NULL)
		return (ft_strdup("$> "));
	i = 0;
	ret = ft_strsplit(path, '/');
	while (ret[i])
		i++;
	if (i == 0)
		i = 1;
	tmp = ret[i - 1];
	i = -1;
	while (ret[++i] != NULL)
	{
		if (ret[i] != tmp)
			ft_strdel(&ret[i]);
	}
	free(ret);
	return (tmp);
}
