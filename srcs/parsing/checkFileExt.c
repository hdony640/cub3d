/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkFileExt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:51:58 by hdony             #+#    #+#             */
/*   Updated: 2023/02/13 15:53:15 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing.h"

void	error_msg(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	check_file_ext1(const char *ptr)
{
	int			i;

	i = 0;
	while (*ptr != '\0')
		ptr++;
	if (ft_strncmp(ptr - 4, ".cub", 4) != 0)
		error_msg("The map file should be a .cub file\n");
}

void	check_file_ext(char *str)
{
	const char	*ptr;

	ptr = str;
	if (!ft_strchr(ptr, 46))
		error_msg("The map file should be a .cub file\n");
	else
		check_file_ext1(ptr);
}
