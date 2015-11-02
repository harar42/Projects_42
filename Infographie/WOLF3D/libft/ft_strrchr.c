/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 16:24:22 by harar             #+#    #+#             */
/*   Updated: 2014/12/09 11:28:45 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	len;
	size_t	i;
	char	*dst;

	dst = NULL;
	i = 0;
	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char*)(s + len));
	while (i < len)
	{
		if (s[i] == (char)c)
			dst = (char*)(s + i);
		i++;
	}
	return (dst);
}
