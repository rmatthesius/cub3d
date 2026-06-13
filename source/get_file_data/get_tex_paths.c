/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:30:13 by jkarras           #+#    #+#             */
/*   Updated: 2024/11/04 13:54:18 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	copy_tex_path(char **tex_path, char *str)
{
	*tex_path = ft_substr(str, 3, ft_strlen(&str[3]) + 1);
	if (*tex_path == NULL)
		return (ft_putendl_fd("Error\nmalloc error", 2), true);
	return (false);
}

bool	get_tex_paths(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(data->mapinfo.file[i], str, 3) == 0)
		{
			if (ft_strncmp(str, "NO", 2) == 0)
				return (copy_tex_path(&data->texinfo.north
						, data->mapinfo.file[i]));
			else if (ft_strncmp(str, "SO", 2) == 0)
				return (copy_tex_path(&data->texinfo.south
						, data->mapinfo.file[i]));
			else if (ft_strncmp(str, "EA", 2) == 0)
				return (copy_tex_path(&data->texinfo.east
						, data->mapinfo.file[i]));
			else if (ft_strncmp(str, "WE", 2) == 0)
				return (copy_tex_path(&data->texinfo.west
						, data->mapinfo.file[i]));
		}
		i++;
	}
	return (ft_printf("Error\n%s not found", str), true);
}
