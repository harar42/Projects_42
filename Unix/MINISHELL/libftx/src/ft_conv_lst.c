/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 12:24:34 by harar             #+#    #+#             */
/*   Updated: 2015/05/26 17:31:51 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"
#include <stdlib.h>
#include "sh1.h"

char		*ft_strchr(const char *s, int c)
{
	const char	*ptr;

	if (s == NULL)
		return (NULL);
	ptr = s;
	while (*ptr != (char)c)
	{
		if (*ptr == 0)
			return (NULL);
		ptr++;
	}
	return (char *)ptr;
}

char		**ft_conv_lst(t_env *env)
{
	t_env	*tmp;
	char	**arr;
	int		i;
	int		count;

	count = 0;
	if (env == NULL)
		return (NULL);
	tmp = env->next;
	while (tmp != env)
	{
		++count;
		tmp = tmp->next;
	}
	if ((arr = malloc(sizeof(char *) * (count + 1))) == NULL)
		X_ERR_LOC("Erreur d'allocation memoire");
	i = -1;
	tmp = env->next;
	while (tmp != env)
	{
		arr[++i] = ftx_strdup(tmp->data);
		tmp = tmp->next;
	}
	arr[++i] = NULL;
	return (arr);
}
