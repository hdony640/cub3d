/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:36:47 by ejoo-tho          #+#    #+#             */
/*   Updated: 2023/02/14 11:29:32 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

/* This function gets the (i,j) of the player from the map. */
t_player	get_player(t_data *data)
{
	t_player	player;
	int			i;
	int			j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'W' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'N' || data->map[i][j] == 'S')
			{
				player.i = i;
				player.j = j;
				player.orientation = get_orientation_player(data->map[i][j]);
			}
		}
	}
	return (player);
}

/* This function gets the orientation of the player from the map. */
int	get_orientation_player(char c)
{
	int	res;

	res = 0;
	if (c == 'W')
		res = WEST;
	else if (c == 'E')
		res = EAST;
	else if (c == 'N')
		res = NORTH;
	else if (c == 'S')
		res = SOUTH;
	else
		error_msg("Wrong direction\n");
	return (res);
}

static void	set_dir(t_dpos *dir, int x, int y)
{
	dir->x = x;
	dir->y = y;
}

/* This function initialises the dir of the ray according to the player's
orientation. */
t_dpos	init_dir(int orientation)
{
	t_dpos	dir;

	set_dir(&dir, 0, 0);
	if (orientation == NORTH)
		set_dir(&dir, -1, 0);
	else if (orientation == EAST)
		set_dir(&dir, 0, 1);
	else if (orientation == SOUTH)
		set_dir(&dir, 1, 0);
	else if (orientation == WEST)
		set_dir(&dir, 0, -1);
	else
		error_msg("Wrong direction\n");
	return (dir);
}

int	get_nb_col(t_data *data)
{
	int	i;
	int	j;
	int	nbr;

	i = 0;
	nbr = 0;
	while (i < data->count_map - 1)
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j > nbr)
			nbr = j;
		i++;
	}
	return (nbr);
}
