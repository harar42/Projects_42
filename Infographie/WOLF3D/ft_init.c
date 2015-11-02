/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 12:42:02 by harar             #+#    #+#             */
/*   Updated: 2015/03/03 16:46:41 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/usr/X11/include/X11/X.h"
#include "libft/libft.h"
#include "ft_wolf.h"
#include <stdlib.h>
#include <mlx.h>

static void ft_inithook(t_env *e)
{
	mlx_hook(e->win, Expose, ExposureMask, ft_expose_hook, e);
	mlx_hook(e->win, KeyPress, KeyPressMask, ft_key_press_hook, e);
	mlx_hook(e->win, KeyRelease, KeyReleaseMask, ft_key_release_hook, e);
	mlx_hook(e->win, ButtonPress, ButtonPressMask, ft_mouse_button_hook, e);
	mlx_hook(e->win, MotionNotify, PointerMotionMask, ft_mouse_motion_hook, e);
	mlx_loop_hook(e->mlx, ft_loop_hook, e);
}

static void	ft_initimg(t_env *e)
{
	t_image i;

	ft_bzero(&i, sizeof(t_image));
	i.img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	i.data = mlx_get_data_addr(i.img, &(i.bpp), &(i.sl), &(i.endian));
	if (!i.img || !i.data)
		exit(ft_perror("[Init]: Initialisation de l'image impossible."));
	e->img = i;
}

static void	ft_initplayer(t_env *e)
{
	t_player p;

	ft_bzero(&p, sizeof(t_player));
	p.pos = e->player.pos;
	p.dir.x = -1;
	p.dir.y = 0;
	e->player = p;
}

void		ft_init(t_env *e)
{
	if ((e->mlx = mlx_init()) == NULL)
		exit(ft_perror("[Init]: Initialisation de la mlx impossible."));
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, WIN_S);
	e->ray.pln.x = 0.0;
	e->ray.pln.y = 0.8;
	e->light = 6;
	e->mouse.x = WIN_X / 2;
	e->mouse.y = WIN_Y / 2;
	ft_initimg(e);
	ft_inithook(e);
	ft_initplayer(e);
}
