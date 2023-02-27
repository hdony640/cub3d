/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:37:36 by ejoo-tho          #+#    #+#             */
/*   Updated: 2023/02/14 11:06:10 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

/* This function initialises the gdata structure. */

void	init_gdata(t_graphdata *gdata, t_data *data, t_ray *ray)
{
	gdata->mlx = NULL;
	gdata->win = NULL;
	gdata->img.img = NULL;
	gdata->img.addr = NULL;
	gdata->img.bits_per_pixel = 0;
	gdata->img.line_length = 0;
	gdata->img.endian = 0;
	gdata->img_2d.img_2d = NULL;
	gdata->img_2d.addr_2d = NULL;
	gdata->img_2d.bits_per_pixel_2d = 0;
	gdata->img_2d.line_length_2d = 0;
	gdata->img_2d.endian_2d = 0;
	gdata->data = data;
	gdata->ray = ray;
	gdata->player = get_player(gdata->data);
	gdata->player_2d = convert_player_pos(gdata->player);
}

static void	create_imgfromtext(t_graphdata *gdata, int i, char *path)
{
	gdata->texture[i].img = mlx_xpm_file_to_image(gdata->mlx, path,
			&gdata->texture[i].width, &gdata->texture[i].height);
	if (!gdata->texture[i].img)
		error_msg("Texture path error\n");
	gdata->texture[i].addr = (int *)mlx_get_data_addr(gdata->texture[i].img,
			&gdata->texture[i].bits_per_pixel, &gdata->texture[i].line_length,
			&gdata->texture[i].endian);
}

/* This function initialises minilibx, the window and the image necessary
to draw the project. */

void	init_graph(t_graphdata *gdata)
{
	gdata->mlx = mlx_init();
	gdata->win = mlx_new_window(gdata->mlx, WIDTH, HEIGHT, "Cub3D");
	gdata->img.img = mlx_new_image(gdata->mlx, WIDTH, HEIGHT);
	gdata->img.addr = (int *)mlx_get_data_addr(gdata->img.img,
			&gdata->img.bits_per_pixel, &gdata->img.line_length,
			&gdata->img.endian);
	create_imgfromtext(gdata, 0, gdata->data->tex_parsing.texture[0]);
	create_imgfromtext(gdata, 1, gdata->data->tex_parsing.texture[1]);
	create_imgfromtext(gdata, 2, gdata->data->tex_parsing.texture[2]);
	create_imgfromtext(gdata, 3, gdata->data->tex_parsing.texture[3]);
	gdata->img_2d.img_2d = mlx_new_image(gdata->mlx,
			(get_nb_col(gdata->data) + 1) * SQRSIDE,
			(gdata->data->count_map + 1) * SQRSIDE);
	gdata->img_2d.addr_2d = mlx_get_data_addr(gdata->img_2d.img_2d,
			&gdata->img_2d.bits_per_pixel_2d, &gdata->img_2d.line_length_2d,
			&gdata->img_2d.endian_2d);
}

/* This function initialises the ray with pos, dir and plane.
** Initializing plane vector
** PI / 2: angle de 90 degré
** passe l'angl et le vecteur que je veux roter
** puis multiplie ce nouvel angle par 0.66
** = vecteur plan de caméra
*/

void	init_ray(t_graphdata *gdata)
{
	gdata->ray->pos.x = gdata->player.i + 0.5;
	gdata->ray->pos.y = gdata->player.j + 0.5;
	gdata->ray->dir = init_dir(gdata->player.orientation);
	gdata->ray->plane = scalar_multiply(0.66,
			rotation(PI / 2, gdata->ray->dir));
	gdata->ray->move_speed = 0.4;
	gdata->ray->rot_speed = 0.4;
}
