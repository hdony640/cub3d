/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:39:56 by hdony             #+#    #+#             */
/*   Updated: 2023/02/14 11:29:06 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

void	execution(t_graphdata *gdata, t_data *data, t_ray *ray)
{
	init_gdata(gdata, data, ray);
	init_graph(gdata);
	init_ray(gdata);
	mlx_hook(gdata->win, 17, 1L << 5, clean_exit, gdata);
	mlx_hook(gdata->win, 2, 0, key_hook, gdata);
	mlx_loop_hook(gdata->mlx, ft_ray, gdata);
	mlx_loop(gdata->mlx);
}

void	parsing(char *argv[], t_data *data)
{
	check_file_ext(argv[1]);
	init_struct(data);
	browse_map(data, argv);
	allocate_map(data, argv);
}

int	main(int argc, char *argv[])
{
	t_data		data;
	t_graphdata	gdata;
	t_ray		ray;

	if (argc != 2)
		error_msg("Incorrect nb of args\n");
	parsing(argv, &data);
	check_map(data.map, &data);
	execution(&gdata, &data, &ray);
	free_alloc(&data);
	return (0);
}
