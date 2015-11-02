/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 15:26:53 by harar             #+#    #+#             */
/*   Updated: 2015/03/03 16:47:20 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_wolf.h"
#include <mlx.h>

int	ft_loop_hook(t_env *e)
{
	int	x;

	if ((x = -1) && e->img.img != NULL)
	{
		mlx_destroy_image(e->mlx, e->img.img);
		e->img.img = NULL;
	}
	e->img.img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	while (++x < WIN_X)
		ft_raycast(e, x);
	ft_getframe(e);
	ft_move(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_env	e;

	if (!*env)
		return (ft_perror("Environnement indisponible."));
	else if (!(argc - 1))
		return (ft_perror("Usage: ./wolf3d [map]"));
	ft_parser(argv[1], &e);
	ft_init(&e);
	mlx_loop(e.mlx);
	return (0);
}
