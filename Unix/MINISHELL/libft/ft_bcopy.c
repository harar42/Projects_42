/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bcopy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 14:04:43 by harar             #+#    #+#             */
/*   Updated: 2015/02/04 14:04:51 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bcopy(char *src, char *dst, unsigned int len)
{
	if (src < dst)
	{
		src += len;
		dst += len;
		while (len--)
			*--dst = *--src;
	}
	else if (src != dst)
		while (len--)
			*dst++ = *src++;
}
