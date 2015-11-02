/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 14:03:35 by harar             #+#    #+#             */
/*   Updated: 2015/02/04 14:05:13 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	if (*s == (char)c)
		return ((char *)s);
	if (!*s)
		return (NULL);
	return (ft_strchr(++s, c));
}
