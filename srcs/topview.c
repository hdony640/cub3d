/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topview.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:59:56 by ejoo-tho          #+#    #+#             */
/*   Updated: 2023/02/14 11:06:10 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

void	draw_player(t_graphdata *gdata)
{
	t_pos	pos;

	pos.x = gdata->player_2d.x - PLAYERSIZE;
	while (pos.x++ <= (gdata->player_2d.x + PLAYERSIZE))
	{
		pos.y = gdata->player_2d.y - PLAYERSIZE;
		while (pos.y++ <= (gdata->player_2d.y + PLAYERSIZE))
			my_mlx_pixel_put(&gdata->img_2d, pos.x, pos.y,
				create_trgb(1, 255, 0, 0));
	}
}

static void	draw_square(t_pos topleft, t_graphdata *gdata, int colour)
{
	t_pos	pos;

	(void) gdata;
	pos.x = topleft.x;
	while (pos.x++ <= (topleft.x + SQRSIDE - 1))
	{
		pos.y = topleft.y;
		while (pos.y++ <= (topleft.y + SQRSIDE - 1))
		{
			if (colour == 1)
				my_mlx_pixel_put(&gdata->img_2d, pos.x, pos.y,
					create_trgb(1, 128, 128, 128));
			else if (colour == 0)
				my_mlx_pixel_put(&gdata->img_2d, pos.x, pos.y,
					create_trgb(1, 66, 179, 245));
		}
	}
}

void	draw_map(t_graphdata *gdata)
{
	int		i;
	int		j;
	t_pos	topleft;

	j = -1;
	topleft.y = 0;
	while (gdata->data->map[++j])
	{
		i = 0;
		topleft.x = 0;
		while (gdata->data->map && gdata->data->map[j][i])
		{
			if (gdata->data->map[j][i] == '1')
				draw_square(topleft, gdata, 1);
			else if (gdata->data->map[j][i] == '0'
					|| gdata->data->map[j][i] == 'E'
					|| gdata->data->map[j][i] == 'W'
					|| gdata->data->map[j][i] == 'N'
					|| gdata->data->map[j][i] == 'S')
				draw_square(topleft, gdata, 0);
			topleft.x += SQRSIDE;
			i++;
		}
		topleft.y += SQRSIDE;
	}
}

int	render_topview(t_graphdata *gdata)
{
	draw_map(gdata);
	draw_player(gdata);
	return (EXIT_SUCCESS);
}
