/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 15:34:49 by harar             #+#    #+#             */
/*   Updated: 2014/12/09 12:23:39 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	i = 0;
	if (s != 0 && (*f) != 0)
	{
		dest = (char*)malloc(ft_strlen(s) + 1);
		while (s[i] != '\0')
		{
			dest[i] = (*f)(i, s[i]);
			i++;
		}
		return (dest);
	}
	return (0);
}
