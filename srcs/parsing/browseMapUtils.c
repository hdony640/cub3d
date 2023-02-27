/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browseMapUtils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:01:01 by hdony             #+#    #+#             */
/*   Updated: 2023/02/14 12:03:23 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*ligne non-vide ou pas que avec des espaces*/
int	line_content(char *ret)
{
	int	i;

	i = 0;
	while (ret[i] && (ret[i] == 9 || (ret[i] >= 11 && ret[i] <= 13)
			|| ret[i] == ' '))
		i++;
	if (ret[i] == '\0')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (!c)
		error_msg("Map error: player can see undefined texture\n");
	if (c == 9 || (c >= 11 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	skip_space(char *ret)
{
	int	i;

	i = 0;
	while (ret[i] && is_space(ret[i]))
		i++;
	return (i);
}

void	open_file(t_data *data, char *argv[])
{
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
		error_msg("Open() error\n");
}

/* if all textures populated & line is not empty, count map
** if line is from the map & all textures not populated, error
*/
void	browse_map_cond(char *ret, t_data *data, int *count)
{
	if (!ft_strncmp(ret, "NO", 2))
		populate_texture(0, data, count, ret);
	else if (!ft_strncmp(ret, "SO", 2))
		populate_texture(1, data, count, ret);
	else if (!ft_strncmp(ret, "WE", 2))
		populate_texture(2, data, count, ret);
	else if (!ft_strncmp(ret, "EA", 2))
		populate_texture(3, data, count, ret);
	else if (!ft_strncmp(ret, "F", 1))
		populate_rgb(0, data, count, ret);
	else if (!ft_strncmp(ret, "C", 1))
		populate_rgb(1, data, count, ret);
	else
	{
		if (!line_content(ret) && *count == 6)
			data->count_map++;
		if (line_content_map(ret) && *count != 6)
			error_msg("Map not at EOF / Incorrect number of texture\n");
	}
}
