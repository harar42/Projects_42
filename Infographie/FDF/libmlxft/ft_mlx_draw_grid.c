/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw_grid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 09:08:15 by harar             #+#    #+#             */
/*   Updated: 2015/02/20 09:22:42 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxft.h"
#include <mlx.h>

void			ft_mlx_draw_grid(t_param *param)
{
	t_dlist		*ptr;

	ptr = param->list;
	while (ptr != 0)
	{
		ft_pixel_put_to_img(ptr->np.x, ptr->np.y, ptr->np.rgb, param);
		if (ptr->next != 0)
		{
			if (ptr->next->p.y == ptr->p.y)
				ft_mlx_draw_line(param, ptr->np, ptr->next->np, LINE_C_SHD);
		}
		if (ptr->down != 0)
			ft_mlx_draw_line(param, ptr->np, ptr->down->np, LINE_C_SHD);
		if (param->color != 1 && ptr->next != 0 && ptr->down != 0 && DN != 0)
		{
			if ((PT2.x == PT4.x) && (PT3.y == PT4.y))
				ft_mlx_draw_line(param, ptr->np, PT5, LINE_C_SHD);
		}
		ptr = ptr->next;
	}
}
