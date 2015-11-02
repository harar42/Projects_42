/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 14:26:51 by harar             #+#    #+#             */
/*   Updated: 2014/12/09 12:18:26 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dest;

	i = 0;
	if (s != 0 && (*f) != 0)
	{
		dest = (char*)malloc(ft_strlen(s) + 1);
		while (s[i] != '\0')
		{
			dest[i] = (*f)(s[i]);
			i++;
		}
		return (dest);
	}
	return (0);
}
