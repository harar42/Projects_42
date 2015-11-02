/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 16:36:47 by harar             #+#    #+#             */
/*   Updated: 2014/12/09 13:55:48 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (size == 0)
		return (NULL);
	str = (char*)malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	while (i < size)
		str[i++] = '\0';
	return ((void*)str);
}
