/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 14:56:48 by harar             #+#    #+#             */
/*   Updated: 2014/12/09 11:29:39 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	const	char	*tmp1;
	const	char	*tmp2;

	if (*to_find == 0)
		return ((char *)str);
	while (*str != 0)
	{
		tmp1 = str;
		tmp2 = to_find;
		while (*tmp1 == *tmp2 && *tmp1 != 0 && *tmp2 != 0)
		{
			tmp1++;
			tmp2++;
		}
		if (*tmp2 == 0)
			return ((char *)str);
		str++;
	}
	return (0);
}
