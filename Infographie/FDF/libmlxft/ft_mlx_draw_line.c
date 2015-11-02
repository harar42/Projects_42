/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 09:08:27 by harar             #+#    #+#             */
/*   Updated: 2015/02/20 09:22:54 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"
#include <math.h>
#include <mlx.h>

#define GET_COLOR(a, b) ft_get_color(a.rgb, (32 - 8 * b))

void				ft_pixel_put_to_img(int x, int y, int c, t_param *s)
{
	unsigned int	color;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (y >= WIN_Y || x >= WIN_X || y < 0 || x < 0)
		return ;
	color = mlx_get_color_value(s->e.mlx, c);
	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	s->data[(y * s->sl) + (x * (s->bpp / 8))] = b;
	s->data[(y * s->sl) + (x * (s->bpp / 8)) + 1] = g;
	s->data[(y * s->sl) + (x * (s->bpp / 8)) + 2] = r;
}

void				ft_mlx_draw_line(t_param *s, t_mlxp p, t_mlxp p2, int opt)
{
	float			incxy[5];
	float			xy[5];
	int				col;
	int				l;
	int				i;

	l = (ABS(p2.y - p.y) > ABS(p2.x - p.x)) ? ABS(p2.y - p.y) : ABS(p2.x - p.x);
	incxy[0] = (float)(p2.x - p.x) / (float)l;
	incxy[1] = (float)(p2.y - p.y) / (float)l;
	i = 1;
	while (++i < 5 && (opt & 1))
		incxy[i] = (float)(GET_COLOR(p2, i) - GET_COLOR(p, i)) / (float)l;
	xy[0] = p.x + 0.5;
	xy[1] = p.y + 0.5;
	i = 1;
	while (++i < 5)
		xy[i] = ft_get_color(p.rgb, 32 - 8 * i) + 0.1;
	while (l-- >= 0 && (i = -1))
	{
		col = ft_get_rgb((int)xy[2], (int)xy[3], (int)xy[4]);
		ft_pixel_put_to_img((int)xy[0], (int)xy[1], col, s);
		while (++i < 5 || ((i < 2) && (opt & 1)))
			xy[i] = xy[i] + incxy[i];
	}
}
