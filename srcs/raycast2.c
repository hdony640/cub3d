/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:11:17 by ejoo-tho          #+#    #+#             */
/*   Updated: 2023/02/14 11:28:43 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

static void	calc_dist_wall(t_ray *ray, t_data *data)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (data->map[ray->map.x][ray->map.y] == '1')
			ray->hit = 1;
	}
}

static void	calc_perp_dist_wall(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

int	ft_ray(t_graphdata *gdata)
{
	int	x;

	if (gdata->img.img)
		recreate_img(gdata);
	if (gdata->img_2d.img_2d)
		recreate_img2d(gdata);
	x = -1;
	while (++x <= WIDTH)
	{
		calc_ray(gdata->ray, x);
		calc_dist_wall(gdata->ray, gdata->data);
		calc_perp_dist_wall(gdata->ray);
		draw_wall(gdata, gdata->ray, x);
		draw_roof_ceiling(gdata, gdata->ray, x);
	}
	mlx_put_image_to_window(gdata->mlx, gdata->win, gdata->img.img, 0, 0);
	render_topview(gdata);
	mlx_put_image_to_window(gdata->mlx, gdata->win,
		gdata->img_2d.img_2d, 20, 20);
	return (EXIT_SUCCESS);
}
