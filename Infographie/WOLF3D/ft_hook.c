/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 08:24:57 by harar             #+#    #+#             */
/*   Updated: 2015/03/03 16:45:51 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_wolf.h"
#include <stdlib.h>

int	ft_mouse_button_hook(int button, int x, int y, t_env *e)
{
	(void)e;
	return (0 * (button >> x >> y));
}

int ft_mouse_motion_hook(int x, int y, t_env *e)
{
	if (x < e->mouse.x)
		e->player.move = MOVE_LEFT;
	else if (x > e->mouse.x)
		e->player.move = MOVE_RIGHT;
	e->mouse.x = x;
	e->mouse.y = y;
	return (0 * (x >> y));
}

int	ft_expose_hook(t_env *e)
{
	(void)e;
	return (0);
}

int	ft_key_press_hook(int k, t_env *e)
{
	if (k == 65361 || k == 97)
		e->player.move = MOVE_LEFT;
	if (k == 65362 || k == 119)
		e->player.move = MOVE_UP;
	if (k == 65363 || k == 100)
		e->player.move = MOVE_RIGHT;
	if (k == 65364 || k == 115)
		e->player.move = MOVE_DOWN;
	if (k == 32)
		e->player.sprint = MOVE_RUN;
	if (k == 65453)
		e->light = (e->light == 10) ? 10 : e->light + 1;
	if (k == 65451)
		e->light = (e->light == 1) ? 1 : e->light - 1;
	return (0);
}

int	ft_key_release_hook(int k, t_env *e)
{
	if (k == 65307)
		exit(0);
	if ((k == 65361 || k == 97) && (e->player.move & MOVE_LEFT))
		e->player.move ^= MOVE_LEFT;
	if ((k == 65362 || k == 119) && (e->player.move & MOVE_UP))
		e->player.move ^= MOVE_UP;
	if ((k == 65363 || k == 100) && (e->player.move & MOVE_RIGHT))
		e->player.move ^= MOVE_RIGHT;
	if ((k == 65364 || k == 115) && (e->player.move & MOVE_DOWN))
		e->player.move ^= MOVE_DOWN;
	if (k == 32 && MOVE_RUN)
		e->player.sprint ^= MOVE_RUN;
	return (0);
}
