/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:07:22 by ejoo-tho          #+#    #+#             */
/*   Updated: 2023/02/14 11:09:53 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

t_dpos	scalar_multiply(double m, t_dpos dpos)
{
	t_dpos	image;

	image.x = dpos.x * m;
	image.y = dpos.y * m;
	return (image);
}

t_dpos	rotation(double a, t_dpos dpos)
{
	t_dpos	image;

	image.x = dpos.x * cos(a) + dpos.y * sin(a);
	image.y = -dpos.x * sin(a) + dpos.y * cos(a);
	return (image);
}

static void	init_side_dist(t_ray *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (ray->pos.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - ray->pos.x) * ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (ray->pos.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - ray->pos.y) * ray->delta_dist.y;
	}
}

void	calc_ray(t_ray *ray, int x)
{
	ray->camera_x = 2 * x / ((double)WIDTH) - 1;
	ray->ray_dir.x = ray->dir.x + ray->plane.x * ray->camera_x;
	ray->ray_dir.y = ray->dir.y + ray->plane.y * ray->camera_x;
	ray->map.x = (int)ray->pos.x;
	ray->map.y = (int)ray->pos.y;
	if (ray->ray_dir.x == 0)
		ray->delta_dist.x = exp(30);
	else
		ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	if (ray->ray_dir.y == 0)
		ray->delta_dist.y = exp(30);
	else
		ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	init_side_dist(ray);
	ray->hit = 0;
}
