/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:52:20 by hdony             #+#    #+#             */
/*   Updated: 2023/02/14 12:05:38 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	line_content_map(char *ret)
{
	int	i;

	i = 0;
	while (ret[i] && (ret[i] == 9 || (ret[i] >= 11 && ret[i] <= 13)
			|| ret[i] == ' '))
			i++;
	if (ret[i] == '1' || ret[i] == '0')
		return (1);
	return (0);
}

void	check_wrong_char(char **map, int count_map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (i < count_map - 1 && map[++i])
	{
		while (map[i][++j])
		{
			if (!is_space(map[i][j]) && map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E'
					&& map[i][j] != 'W')
				error_msg("Wrong char in map\n");
		}
		j = -1;
	}
}

void	check_dup_char(char **map)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	j = -1;
	count = 0;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				count++;
		}
		j = -1;
	}
	if (count > 1 || count < 1)
		error_msg("Incorrect number of player\n");
}

void	check_empty_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (line_content(map[i]))
			error_msg("Empty line in map\n");
		i++;
	}
}

/* Perform various quality checks on the map */
void	check_map(char **map, t_data *data)
{
	check_wrong_char(map, data->count_map);
	check_dup_char(map);
	check_empty_line(map);
	check_delim_line(map, data->count_map);
	check_delim_char(map);
	check_gaps(map, data->count_map);
}
