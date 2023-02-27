/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:10:23 by elsajoo-tho       #+#    #+#             */
/*   Updated: 2023/02/14 11:28:01 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../minilibx/mlx.h"
# include "parsing.h"
# include <math.h>

# define WIDTH 1200
# define HEIGHT 750
# define SQRSIDE 4
# define PLAYERSIZE 1
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define PI 3.141592654

enum	e_s_keys
{
	LEFT	= 124,
	RIGHT	= 123,
	W		= 13,
	A		= 0,
	S		= 1,
	D		= 2,
	ESC		= 53,
	SPACE	= 49,
	SHIFT	= 257
};

typedef struct s_pos
{
	int		x;
	int		y;
}	t_pos;

typedef struct s_dpos
{
	double	x;
	double	y;
}	t_dpos;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_img2d
{
	void	*img_2d;
	char	*addr_2d;
	int		bits_per_pixel_2d;
	int		line_length_2d;
	int		endian_2d;
}	t_img2d;

typedef struct s_player
{
	int	i;
	int	j;
	int	orientation;
}	t_player;

typedef struct s_tex
{
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		orientation;
}	t_tex;

typedef struct s_ray
{
	t_dpos	pos;
	t_dpos	dir;
	t_dpos	plane;
	double	camera_x;
	t_dpos	ray_dir;
	t_pos	map;
	t_dpos	side_dist;
	t_dpos	delta_dist;
	double	perp_wall_dist;
	t_pos	step;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	move_speed;
	double	rot_speed;
}	t_ray;

typedef struct s_graphdata
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_img2d		img_2d;
	t_player	player;
	t_pos		player_2d;
	t_data		*data;
	t_ray		*ray;
	t_img		texture[4];
}	t_graphdata;

//graph_utils
void		my_mlx_pixel_put(t_img2d *data, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
void		recreate_img(t_graphdata *gdata);
void		recreate_img2d(t_graphdata *gdata);
t_pos		convert_player_pos(t_player player);

//topview
void		draw_player(t_graphdata *gdata);
void		draw_map(t_graphdata *gdata);
int			render_topview(t_graphdata *gdata);

//hooks
int			key_hook(int keycode, t_graphdata *gdata);

//player_mvt2D
void		move_2D(t_graphdata *gdata);

//player_mvt3D
void		move_up(t_graphdata *gdata);
void		move_down(t_graphdata *gdata);
void		move_right(t_graphdata *gdata);
void		move_left(t_graphdata *gdata);
void		rotate_right(t_graphdata *gdata);
void		rotate_left(t_graphdata *gdata);

//init_utils
t_player	get_player(t_data *data);
int			get_orientation_player(char c);
t_dpos		init_dir(int orientation);
int			get_nb_col(t_data *data);

//init
void		init_gdata(t_graphdata *gdata, t_data *data, t_ray *ray);
void		init_graph(t_graphdata *gdata);
void		init_ray(t_graphdata *gdata);

//graph
void		clean_data(t_graphdata *gdata);
int			clean_exit(t_graphdata *gdata);

//raycast1
t_dpos		scalar_multiply(double m, t_dpos dpos);
t_dpos		rotation(double a, t_dpos dpos);
void		calc_ray(t_ray *ray, int x);

//raycast2
int			ft_ray(t_graphdata *gdata);

//render
void		draw_wall(t_graphdata *gdata, t_ray *ray, int x);
void		draw_roof_ceiling(t_graphdata *gdata, t_ray *ray, int x);

#endif