/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 09:27:59 by harar             #+#    #+#             */
/*   Updated: 2015/05/11 10:49:48 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrep(char *str, char const *sub, char const *rep, int recursive)
{
	char	*result;
	char	*pos[2];
	int		f;

	f = 0;
	pos[0] = str;
	while ((pos[0] = ft_strstr(pos[0], sub)) && f++)
		pos[0] += ft_strlen(sub);
	f = ((ft_strlen(str) - (ft_strlen(sub) * f)) + (ft_strlen(rep) * f)) + 1;
	result = (char *)ft_memalloc(f);
	pos[0] = str;
	while ((pos[1] = ft_strstr(pos[0], sub)))
	{
		f = (pos[1] - pos[0]);
		ft_strncat(result, pos[0], f);
		ft_strncat(result, rep, ft_strlen(rep));
		pos[0] = (pos[1] + ft_strlen(sub));
		if (recursive == REPLACE_ONCE)
			break ;
	}
	if (pos[0] != (str + ft_strlen(str)))
		ft_strncat(result, pos[0], (str - pos[0]));
	return (result);
}
