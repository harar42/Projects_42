/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 14:03:10 by harar             #+#    #+#             */
/*   Updated: 2015/02/04 14:05:08 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1 = ft_strdup((char *)s1);
	s2 = ft_strdup((char *)s2);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (str != NULL)
	{
		ft_strncpy(str, s1, ft_strlen(s1));
		ft_strncat(str, s2, ft_strlen(s2));
	}
	free((void *)s1);
	free((void *)s2);
	return (str);
}
