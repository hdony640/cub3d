/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browseMap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:02:29 by hdony             #+#    #+#             */
/*   Updated: 2023/02/14 11:42:01 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_overflow(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255)
		error_msg("Texture resolution above 255\n");
	else if (r < 0 || g < 0 || b < 0)
		error_msg("Texture resolution are negative\n");
}

void	populate_texture(int idx, t_data *data, int *count, char *ret)
{
	int	i;

	i = skip_space(ret + 2);
	data->tex_parsing.texture[idx] = ft_strdup(ret + i + 2);
	*count += 1;
}

void	color_check(char **split)
{
	int	i;
	int	j;

	i = -1;
	while (split[++i])
	{	
		j = skip_space(split[i]);
		if (split[i][j] == '\0')
			error_msg("Empty value in rgb\n");
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j]) && !is_space(split[i][j]))
				error_msg("Non digit value in rgb\n");
			j++;
		}
		j = 0;
	}
	if (i < 3)
		error_msg("Incorrect format for RGB values\n");
}

/* Split rgb values, perform check on rgb values, atoi rgb values, free split */
void	populate_rgb(int idx, t_data *data, int *count, char *ret)
{
	int		i;
	char	**split;

	i = skip_space(ret + 1);
	split = ft_split(ret + i, ',');
	color_check(split);
	data->rgb[idx].r = ft_atoi(split[0]);
	data->rgb[idx].g = ft_atoi(split[1]);
	data->rgb[idx].b = ft_atoi(split[2]);
	check_overflow(data->rgb[idx].r, data->rgb[idx].g, data->rgb[idx].b);
	free_split(split);
	*count += 1;
}

/* Open the file, read each line with gnl, populate the texture
** & rgb structures, count # lines of the map, count # lines before the map */
void	browse_map(t_data *data, char *argv[])
{
	char	*ret;
	int		count;

	count = 0;
	open_file(data, argv);
	if (data->fd < 0)
		error_msg("Open error\n");
	ret = get_next_line(data->fd);
	while (ret)
	{
		browse_map_cond(ret, data, &count);
		if (!data->count_map)
			data->count_file++;
		free(ret);
		ret = get_next_line(data->fd);
	}
	if (count != 6)
		error_msg("Incorrect number of texture\n");
	close(data->fd);
}
