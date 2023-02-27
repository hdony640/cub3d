/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:17:47 by elsajoo-tho       #+#    #+#             */
/*   Updated: 2023/02/14 11:29:57 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

/* This function cleans up the data struture. */
void	clean_data(t_graphdata *gdata)
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
}

/* This function destroys all that needs to be destroyed, cleans the data
structure and exits the programme upon success. */
int	clean_exit(t_graphdata *gdata)
{
	mlx_destroy_image(gdata->mlx, gdata->img.img);
	mlx_destroy_image(gdata->mlx, gdata->img_2d.img_2d);
	mlx_destroy_window(gdata->mlx, gdata->win);
	clean_data(gdata);
	free(gdata->mlx);
	exit(EXIT_SUCCESS);
}
