/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 12:21:28 by harar             #+#    #+#             */
/*   Updated: 2015/03/04 11:37:42 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

static int	ft_get_color(int rgb, int opt)
{
	return ((rgb >> opt) & 0xFF);
}

static int	ft_deepcolor(t_env *e, int color)
{
	int r;
	int g;
	int b;

	r = 0;
	g = 0;
	b = 0;
	if (ft_get_color(color, GET_RED) & 0xFF)
		r = (e->ray.line.y - e->ray.line.x) * 255 / WIN_Y + (255 / e->light);
	if (ft_get_color(color, GET_GREEN) & 0xFF)
		g = (e->ray.line.y - e->ray.line.x) * 255 / WIN_Y + (255 / e->light);
	if (ft_get_color(color, GET_BLUE) & 0xFF)
		b = (e->ray.line.y - e->ray.line.x) * 255 / WIN_Y + (255 / e->light);
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (C(r, g, b));
}

int			ft_getcolor(t_env *e)
{
	if (e->player.wallside == 0)
	{
		if (e->player.step.x < 0)
			return (ft_deepcolor(e, C(255, 255, 255)));
		return (ft_deepcolor(e, C(0, 255, 255)));
	}
	if (e->player.step.y < 0)
		return (ft_deepcolor(e, C(255, 0, 255)));
	return (ft_deepcolor(e, C(255, 255, 0)));
}
