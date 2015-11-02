/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 12:23:11 by harar             #+#    #+#             */
/*   Updated: 2015/03/03 16:43:55 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"
#include <sys/time.h>
#include <math.h>
#include <mlx.h>

static void ft_rot(t_env *e, int dir)
{
	double	tmp;
	double	plane;
	int		coef;

	coef = (dir & MOVE_RIGHT) ? -1 : 1;
	tmp = e->player.dir.x;
	plane = e->ray.pln.x;
	e->player.dir.x = e->player.dir.x * cos(coef * e->player.rot_spd)
		- e->player.dir.y * sin(coef * e->player.rot_spd);
	e->player.dir.y = tmp * sin(coef * e->player.rot_spd)
		+ e->player.dir.y * cos(coef * e->player.rot_spd);
	e->ray.pln.x = e->ray.pln.x * cos(coef * e->player.rot_spd)
		- e->ray.pln.y * sin(coef * e->player.rot_spd);
	e->ray.pln.y = plane * sin(coef * e->player.rot_spd)
		+ e->ray.pln.y * cos(coef * e->player.rot_spd);
	if (e->player.move & MOVE_LEFT)
		e->player.move ^= MOVE_LEFT;
	if (e->player.move & MOVE_RIGHT)
		e->player.move ^= MOVE_RIGHT;
}

void		ft_move(t_env *e)
{
	if (e->player.move & MOVE_UP)
	{
		if (!(e->map.map[(int)(e->player.pos.x + e->player.dir.x
					* e->player.mov_spd)][(int)(e->player.pos.y)]))
			e->player.pos.x += e->player.dir.x * e->player.mov_spd;
		if (!(e->map.map[(int)(e->player.pos.x)][(int)(e->player.pos.y
								+ e->player.dir.y * e->player.mov_spd)]))
			e->player.pos.y += e->player.dir.y * e->player.mov_spd;
	}
	if ((e->player.move & MOVE_LEFT) || (e->player.move & MOVE_RIGHT))
		ft_rot(e, (e->player.move & MOVE_LEFT) ? MOVE_LEFT : MOVE_RIGHT);
	if (e->player.move & MOVE_DOWN)
	{
		if (!(e->map.map[(int)(e->player.pos.x - e->player.dir.x
						* e->player.mov_spd)][(int)(e->player.pos.y)]))
			e->player.pos.x -= e->player.dir.x * e->player.mov_spd;
		if (!(e->map.map[(int)(e->player.pos.x)][(int)(e->player.pos.y
						- e->player.dir.y * e->player.mov_spd)]))
			e->player.pos.y -= e->player.dir.y * e->player.mov_spd;
	}
	if (e->player.sprint)
		e->player.mov_spd *= 0.05;
}

static void	ft_pix_to_img(t_env *e, t_image *img, t_icoord p, int c)
{
	if (p.y >= WIN_Y || p.x >= WIN_X || p.y < 0 || p.x < 0)
		return ;
	c = mlx_get_color_value(e->mlx, c);
	img->data[(p.y * img->sl) + (p.x * (img->bpp / 8)) + 0] = (c >> 16) & 0xFF;
	img->data[(p.y * img->sl) + (p.x * (img->bpp / 8)) + 1] = (c >> 8) & 0xFF;
	img->data[(p.y * img->sl) + (p.x * (img->bpp / 8)) + 2] = (c >> 0) & 0xFF;
}

void		ft_getframe(t_env *e)
{
	struct timeval time;

	e->oldtime = e->time;
	gettimeofday(&time, NULL);
	e->time = time.tv_sec * 1000 + time.tv_usec / 1000;
	e->frametime = e->time - e->oldtime;
	e->player.mov_spd = e->frametime * 0.003;
	e->player.rot_spd = e->frametime * 0.005;
}

void		ft_drawline(int x, t_env *e)
{
	t_icoord	p;
	int			skyfloor;
	int			color;

	color = ft_getcolor(e);
	p.x = x;
	e->img.data = mlx_get_data_addr(e->img.img, &(e->img.bpp), &(e->img.sl),
															&(e->img.endian));
	skyfloor = C(128, 128, 128);
	p.y = -1;
	while (++p.y < e->ray.line.x)
		ft_pix_to_img(e, &(e->img), p, skyfloor);
	p.y = e->ray.line.x - 1;
	while (++p.y < e->ray.line.y)
		ft_pix_to_img(e, &(e->img), p, color);
	skyfloor = C(102, 51, 0);
	p.y = e->ray.line.y - 1;
	while (++p.y < WIN_Y)
		ft_pix_to_img(e, &(e->img), p, skyfloor);
}
