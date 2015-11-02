/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:53:15 by harar             #+#    #+#             */
/*   Updated: 2015/03/04 11:27:24 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WOLF_H
# define FT_WOLF_H

# define WIN_X		800
# define WIN_Y		600
# define WIN_S		"Wolfenstein 3D - HARAR"

# define MOVE_RUN	0x1
# define MOVE_UP	0x1
# define MOVE_DOWN	0x2
# define MOVE_LEFT	0x4
# define MOVE_RIGHT	0x8

# define GET_RED	0x10
# define GET_BLUE	0x00
# define GET_GREEN	0x08

# define PYT(a, b)	((a * a) / (b * b))
# define C(r, g, b)	(((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF))

typedef struct		s_fcoord
{
	double			x;
	double			y;
}					t_fcoord;

typedef struct		s_icoord
{
	int				x;
	int				y;
}					t_icoord;

typedef struct		s_image
{
	void			*img;
	char			*data;
	int				endian;
	int				bpp;
	int				sl;
}					t_image;

typedef struct		s_map
{
	int				**map;
	unsigned int	x;
	unsigned int	y;
}					t_map;

typedef struct		s_player
{
	unsigned int	move;
	t_fcoord		pos;
	t_fcoord		dir;
	t_icoord		step;
	double			rot_spd;
	double			mov_spd;
	double			hcamera;
	unsigned char	hit;
	unsigned char	sprint;
	int				wallside;
}					t_player;

typedef struct		s_ray
{
	t_fcoord		pos;
	t_fcoord		dir;
	t_fcoord		pln;
	t_fcoord		dst;
	t_fcoord		dsd;
	t_icoord		posmap;
	t_icoord		line;
	int				lheight;
}					t_ray;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_ray			ray;
	t_image			img;
	t_player		player;
	t_map			map;
	double			time;
	double			oldtime;
	long int		frametime;
	int				light;
	t_icoord		mouse;
}					t_env;

int					ft_perror(char const *msg);
void				ft_parser(char *file, t_env *e);
void				ft_init(t_env *e);
void				ft_move(t_env *e);
void				ft_raycast(t_env *e, unsigned int x);
void				ft_drawline(int x, t_env *e);
int					ft_getcolor(t_env *e);
void				ft_getframe(t_env *e);

int					ft_loop_hook(t_env *e);
int					ft_expose_hook(t_env *e);
int					ft_key_press_hook(int keycode, t_env *e);
int					ft_key_release_hook(int keycode, t_env *e);
int					ft_mouse_button_hook(int button, int x, int y, t_env *e);
int					ft_mouse_motion_hook(int x, int y, t_env *e);

#endif
