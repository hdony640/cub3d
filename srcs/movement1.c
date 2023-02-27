/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:18:55 by hdony             #+#    #+#             */
/*   Updated: 2023/02/14 11:06:10 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

void	move_up(t_graphdata *gdata)
{
	if (gdata->data->map[(int)(gdata->ray->pos.x + gdata->ray->dir.x
			* gdata->ray->move_speed)][(int)gdata->ray->pos.y] != '1')
		gdata->ray->pos.x += gdata->ray->dir.x * gdata->ray->move_speed;
	if (gdata->data->map[(int)gdata->ray->pos.x][(int)(gdata->ray->pos.y
		+ gdata->ray->dir.y * gdata->ray->move_speed)] != '1')
		gdata->ray->pos.y += gdata->ray->dir.y * gdata->ray->move_speed;
	gdata->player_2d.x = gdata->ray->pos.y * SQRSIDE;
	gdata->player_2d.y = gdata->ray->pos.x * SQRSIDE;
}

void	move_down(t_graphdata *gdata)
{
	if (gdata->data->map[(int)(gdata->ray->pos.x - gdata->ray->dir.x
			* gdata->ray->move_speed)][(int)gdata->ray->pos.y] != '1')
		gdata->ray->pos.x -= gdata->ray->dir.x * gdata->ray->move_speed;
	if (gdata->data->map[(int)gdata->ray->pos.x][(int)(gdata->ray->pos.y
		- gdata->ray->dir.y * gdata->ray->move_speed)] != '1')
		gdata->ray->pos.y -= gdata->ray->dir.y * gdata->ray->move_speed;
	gdata->player_2d.x = gdata->ray->pos.y * SQRSIDE;
	gdata->player_2d.y = gdata->ray->pos.x * SQRSIDE;
}

void	move_left(t_graphdata *gdata)
{
	if (gdata->data->map[(int)(gdata->ray->pos.x - gdata->ray->dir.y
			* gdata->ray->move_speed)][(int)gdata->ray->pos.y] != '1')
		gdata->ray->pos.x -= gdata->ray->dir.y * gdata->ray->move_speed;
	if (gdata->data->map[(int)gdata->ray->pos.x][(int)(gdata->ray->pos.y
		+ gdata->ray->dir.x * gdata->ray->move_speed)] != '1')
		gdata->ray->pos.y += gdata->ray->dir.x * gdata->ray->move_speed;
	gdata->player_2d.x = gdata->ray->pos.y * SQRSIDE;
	gdata->player_2d.y = gdata->ray->pos.x * SQRSIDE;
}

void	move_right(t_graphdata *gdata)
{
	if (gdata->data->map[(int)(gdata->ray->pos.x + gdata->ray->dir.y
			* gdata->ray->move_speed)][(int)gdata->ray->pos.y] != '1')
		gdata->ray->pos.x += gdata->ray->dir.y * gdata->ray->move_speed;
	if (gdata->data->map[(int)gdata->ray->pos.x][(int)(gdata->ray->pos.y
		- gdata->ray->dir.x * gdata->ray->move_speed)] != '1')
		gdata->ray->pos.y -= gdata->ray->dir.x * gdata->ray->move_speed;
	gdata->player_2d.x = gdata->ray->pos.y * SQRSIDE;
	gdata->player_2d.y = gdata->ray->pos.x * SQRSIDE;
}

//both camera direction and camera plane must be rotated
void	rotate_right(t_graphdata *gdata)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = gdata->ray->dir.x;
	old_planex = gdata->ray->plane.x;
	gdata->ray->dir.x = gdata->ray->dir.x * cos(-gdata->ray->rot_speed)
		- gdata->ray->dir.y * sin(-gdata->ray->rot_speed);
	gdata->ray->dir.y = old_dirx * sin(-gdata->ray->rot_speed)
		+ gdata->ray->dir.y * cos(-gdata->ray->rot_speed);
	gdata->ray->plane.x = gdata->ray->plane.x * cos(-gdata->ray->rot_speed)
		- gdata->ray->plane.y * sin(-gdata->ray->rot_speed);
	gdata->ray->plane.y = old_planex * sin(-gdata->ray->rot_speed)
		+ gdata->ray->plane.y * cos(-gdata->ray->rot_speed);
}
