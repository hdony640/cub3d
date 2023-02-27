/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:33:33 by ejoo-tho          #+#    #+#             */
/*   Updated: 2023/02/14 11:27:18 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

int	tex_get_orientation(t_ray *ray)
{
	if (ray->side == 1)
	{
		if (ray->map.y - ray->pos.y > 0)
			return (2);
		else
			return (3);
	}
	else
	{
		if (ray->map.x - ray->pos.x > 0)
			return (1);
		else
			return (0);
	}
	return (0);
}	

void	get_tex_value(t_graphdata *gdata, t_ray *ray, t_tex *tex)
{
	tex->orientation = tex_get_orientation(ray);
	if (ray->side == 0)
		tex->wall_x = ray->pos.y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		tex->wall_x = ray->pos.x + ray->perp_wall_dist * ray->ray_dir.x;
	tex->wall_x -= floor((tex->wall_x));
	tex->tex_x = (tex->wall_x * gdata->texture[tex->orientation].width);
	if (ray->side == 0 && ray->ray_dir.x > 0)
		tex->tex_x = gdata->texture[tex->orientation].width - tex->tex_x -1;
	if (ray->side == 1 && ray->ray_dir.y < 0)
		tex->tex_x = gdata->texture[tex->orientation].width - tex->tex_x -1;
	tex->step = 1.0 * gdata->texture[tex->orientation].height
		/ ray->line_height;
	tex->tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2)
		* tex->step;
}

void	draw_wall(t_graphdata *gdata, t_ray *ray, int x)
{
	t_tex	tex;
	int		y;

	get_tex_value(gdata, ray, &tex);
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex.tex_y = (int)tex.tex_pos & (gdata->texture[tex.orientation].height
				- 1);
		tex.tex_pos += tex.step;
		if (y <= HEIGHT && x <= WIDTH)
		{
			gdata->img.addr[y * gdata->img.line_length / 4 + x]
				= gdata->texture[tex.orientation].addr[tex.tex_y
				* gdata->texture[tex.orientation].line_length / 4 + tex.tex_x];
		}
		y++;
	}
}

void	draw_roof_ceiling(t_graphdata *gdata, t_ray *ray, int x)
{
	int	y;

	if (ray->draw_end < 0)
		ray->draw_end = HEIGHT;
	y = ray->draw_end;
	while (y < HEIGHT - 1)
	{
		gdata->img.addr[y * gdata->img.line_length / 4 + x]
			= create_trgb(1, gdata->data->rgb[0].r,
				gdata->data->rgb[0].g, gdata->data->rgb[0].b);
		y++;
	}
	y = ray->draw_start - 1;
	while (y >= 0)
	{
		gdata->img.addr[y * gdata->img.line_length / 4 + x]
			= create_trgb(1, gdata->data->rgb[1].r,
				gdata->data->rgb[1].g, gdata->data->rgb[1].b);
		y--;
	}
}
