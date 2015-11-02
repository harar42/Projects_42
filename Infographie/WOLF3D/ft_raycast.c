/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 12:50:26 by harar             #+#    #+#             */
/*   Updated: 2015/03/04 13:47:53 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_wolf.h"
#include <math.h>

static void	ft_initray(t_env *e, int x)
{
	e->player.hcamera = 2 * x / (double)(WIN_X) - 1;
	e->ray.pos.x = e->player.pos.x;
	e->ray.pos.y = e->player.pos.y;
	e->ray.dir.x = e->player.dir.x + e->ray.pln.x * e->player.hcamera;
	e->ray.dir.y = e->player.dir.y + e->ray.pln.y * e->player.hcamera;
	e->ray.posmap.x = (int)e->ray.pos.x;
	e->ray.posmap.y = (int)e->ray.pos.y;
	e->ray.dsd.x = sqrt(1 + PYT(e->ray.dir.y, e->ray.dir.x));
	e->ray.dsd.y = sqrt(1 + PYT(e->ray.dir.x, e->ray.dir.y));
	e->player.hit = 0;
}

static void ft_raydir(t_env *e)
{
	if (e->ray.dir.x < 0 && (e->player.step.x = -1))
		e->ray.dst.x = (e->ray.pos.x - e->ray.posmap.x) * e->ray.dsd.x;
	else if ((e->player.step.x = 1))
		e->ray.dst.x = (e->ray.posmap.x + 1.0 - e->ray.pos.x) * e->ray.dsd.x;
	if (e->ray.dir.y < 0 && (e->player.step.y = -1))
		e->ray.dst.y = (e->ray.pos.y - e->ray.posmap.y) * e->ray.dsd.y;
	else if ((e->player.step.y = 1))
		e->ray.dst.y = (e->ray.posmap.y + 1.0 - e->ray.pos.y) * e->ray.dsd.y;
}

static void ft_dda(t_env *e)
{
	while (!e->player.hit)
	{
		if (e->ray.dst.x < e->ray.dst.y)
		{
			e->ray.dst.x += e->ray.dsd.x;
			e->ray.posmap.x += e->player.step.x;
			e->player.wallside = 0;
		}
		else
		{
			e->ray.dst.y += e->ray.dsd.y;
			e->ray.posmap.y += e->player.step.y;
			e->player.wallside = 1;
		}
		if (e->map.map[e->ray.posmap.x][e->ray.posmap.y] != 0)
			e->player.hit = 1;
	}
}

static void	ft_compute(t_env *e)
{
	double distwall;

	if (!e->player.wallside)
		distwall = fabs((e->ray.posmap.x - e->ray.pos.x
						+ (1 - e->player.step.x) / 2) / e->ray.dir.x);
	else
		distwall = fabs((e->ray.posmap.y - e->ray.pos.y
						+ (1 - e->player.step.y) / 2) / e->ray.dir.y);
	e->ray.lheight = ft_abs((int)(WIN_Y / distwall));
	e->ray.line.x = ((e->ray.lheight) * -1) / 2 + WIN_Y / 2;
	if (e->ray.line.x < 0)
		e->ray.line.x = 0;
	e->ray.line.y = e->ray.lheight / 2 + WIN_Y / 2;
	if (e->ray.line.y >= WIN_Y)
		e->ray.line.y = WIN_Y - 1;
}

void		ft_raycast(t_env *e, unsigned int x)
{
	ft_initray(e, (int)x);
	ft_raydir(e);
	ft_dda(e);
	ft_compute(e);
	ft_drawline((int)x, e);
}
