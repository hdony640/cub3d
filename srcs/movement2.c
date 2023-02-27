/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:32:06 by hdony             #+#    #+#             */
/*   Updated: 2023/02/14 10:52:59 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

void	rotate_left(t_graphdata *gdata)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = gdata->ray->dir.x;
	old_planex = gdata->ray->plane.x;
	gdata->ray->dir.x = gdata->ray->dir.x * cos(-gdata->ray->rot_speed)
		- gdata->ray->dir.y * sin(gdata->ray->rot_speed);
	gdata->ray->dir.y = old_dirx * sin(gdata->ray->rot_speed)
		+ gdata->ray->dir.y * cos(gdata->ray->rot_speed);
	gdata->ray->plane.x = gdata->ray->plane.x * cos(-gdata->ray->rot_speed)
		- gdata->ray->plane.y * sin(gdata->ray->rot_speed);
	gdata->ray->plane.y = old_planex * sin(gdata->ray->rot_speed)
		+ gdata->ray->plane.y * cos(-gdata->ray->rot_speed);
}
