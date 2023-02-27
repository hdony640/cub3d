/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:49:50 by hdony             #+#    #+#             */
/*   Updated: 2023/02/14 10:44:34 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_tex_parsing
{
	char	*texture[4];
}	t_tex_parsing;

/* 0 Floor, 1 Ceiling */
typedef struct s_data
{
	int				fd;
	int				count_file;
	int				count_map;
	char			**map;
	t_rgb			rgb[2];
	t_tex_parsing	tex_parsing;
	int				x;
	int				y;
}	t_data;

void	check_file_ext(char *str);
void	init_struct(t_data *data);
void	error_msg(char *str);
void	browse_map(t_data *data, char *argv[]);
int		line_content(char *ret);
int		skip_space(char *ret);
void	open_file(t_data *data, char *argv[]);
void	free_split(char **split);
void	allocate_map(t_data *data, char *argv[]);
void	check_map(char **map, t_data *data);
int		line_content_map(char *ret);
int		is_space(char c);
void	check_delim_char(char **map);
int		check_lastchar(char *str);
void	check_gaps(char **map, int count_map);
void	check_delim_line(char **map, int count_map);
void	free_alloc(t_data *data);
void	browse_map_cond(char *ret, t_data *data, int *count);
void	populate_texture(int idx, t_data *data, int *count, char *ret);
void	populate_rgb(int idx, t_data *data, int *count, char *ret);

#endif
