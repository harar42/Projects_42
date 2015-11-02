/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 12:26:45 by harar             #+#    #+#             */
/*   Updated: 2015/05/11 12:26:49 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ftx_strdup(char *src)
{
	int		i;
	int		str_source_size;
	char	*str;

	i = 0;
	str_source_size = 0;
	while (src[str_source_size] != '\0')
		str_source_size++;
	if ((str = (char *)malloc(sizeof(src) * (str_source_size + 1))) == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
