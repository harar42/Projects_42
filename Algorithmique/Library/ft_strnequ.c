/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 17:54:49 by harar             #+#    #+#             */
/*   Updated: 2014/12/09 13:25:41 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		ret;

	if (!s1 || !s2)
		return (0);
	ret = ft_strncmp(s1, s2, n);
	if (ret == 0)
		return (1);
	return (0);
}
