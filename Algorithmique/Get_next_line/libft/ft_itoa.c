/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 19:13:32 by harar             #+#    #+#             */
/*   Updated: 2014/12/09 11:24:16 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbdigit(int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		digit++;
	}
	return (digit);
}

static int	ft_tenpower(int power)
{
	int	result;
	int	i;

	i = 0;
	result = 1;
	while (i++ < power)
		result = result * 10;
	return (result);
}

char		*ft_itoa(int n)
{
	char			*result;
	unsigned int	nn;
	size_t			i;
	int				digit;

	digit = ft_nbdigit(n);
	i = 0;
	result = (char*)malloc(sizeof(char) * (digit + 2));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[i++] = '-';
		nn = (unsigned int)-n;
	}
	else
		nn = (unsigned int)n;
	while (digit)
	{
		result[i++] = '0' + (char)((nn / ft_tenpower(digit - 1)) % 10);
		digit--;
	}
	result[i] = '\0';
	return (result);
}
