/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:38:15 by ejoo-tho          #+#    #+#             */
/*   Updated: 2023/02/14 11:29:36 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

/* This function codes for key hooks: ESC to exit the programme, as well as 
awsd to move the player and <- -> to turn the player. */
int	key_hook(int keycode, t_graphdata *gdata)
{
	if (keycode == D)
		move_right(gdata);
	else if (keycode == A)
		move_left(gdata);
	else if (keycode == W)
		move_up(gdata);
	else if (keycode == S)
		move_down(gdata);
	else if (keycode == 124)
		rotate_right(gdata);
	else if (keycode == 123)
		rotate_left(gdata);
	else if (keycode == ESC)
	{
		clean_exit(gdata);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
