/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:35:27 by ejoo-tho          #+#    #+#             */
/*   Updated: 2023/02/14 11:29:51 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

/* This function puts a pixel to an image. */
void	my_mlx_pixel_put(t_img2d *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr_2d + (y * data->line_length_2d
			+ x * (data->bits_per_pixel_2d / 8));
	*(unsigned int *)dst = color;
}

/* This function takes the RGB values ranging 0-255 and puts them into TRGB 
hexadecimal format. */
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/* This function destroy the previous image and creates a new one. */
void	recreate_img(t_graphdata *gdata)
{
	mlx_destroy_image(gdata->mlx, gdata->img.img);
	gdata->img.img = mlx_new_image(gdata->mlx, WIDTH, HEIGHT);
	gdata->img.addr = (int *)mlx_get_data_addr(gdata->img.img,
			&gdata->img.bits_per_pixel,
			&gdata->img.line_length, &gdata->img.endian);
}

void	recreate_img2d(t_graphdata *gdata)
{
	mlx_destroy_image(gdata->mlx, gdata->img_2d.img_2d);
	gdata->img_2d.img_2d = mlx_new_image(gdata->mlx,
			(get_nb_col(gdata->data) + 1) * SQRSIDE,
			(gdata->data->count_map + 1) * SQRSIDE);
	gdata->img_2d.addr_2d = mlx_get_data_addr(gdata->img_2d.img_2d,
			&gdata->img_2d.bits_per_pixel_2d,
			&gdata->img_2d.line_length_2d, &gdata->img_2d.endian_2d);
}

/* This function takes a t_player variable and transforms it into it (x,y) pixel
coordinates on the 2D plane. */
t_pos	convert_player_pos(t_player player)
{
	t_pos	pos_player;

	pos_player.x = player.j * SQRSIDE + SQRSIDE / 2;
	pos_player.y = player.i * SQRSIDE + SQRSIDE / 2;
	return (pos_player);
}
