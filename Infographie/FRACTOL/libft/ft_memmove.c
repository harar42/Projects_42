/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 12:44:00 by harar             #+#    #+#             */
/*   Updated: 2014/12/09 11:25:15 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	tmp[n];
	char	*pdest;
	char	*psrc;
	size_t	i;

	i = 0;
	pdest = (char *)dest;
	psrc = (char *)src;
	if (n == 0)
		return (0);
	while (i < n)
	{
		tmp[i] = psrc[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		pdest[i] = tmp[i];
		i++;
	}
	return (pdest);
}
