/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:29:11 by jkarras           #+#    #+#             */
/*   Updated: 2024/11/04 13:54:18 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	copy_tex_colors(int	*int_arr, char **rgb)
{
	if (rgb == NULL)
		return (ft_putendl_fd("Error\nmalloc error", 2), true);
	if (arr_len(rgb) != 3)
		return (ft_putendl_fd("Error\nwrong arg nb : color code", 2), true);
	int_arr[0] = ft_atoi(rgb[0]);
	int_arr[1] = ft_atoi(rgb[1]);
	int_arr[2] = ft_atoi(rgb[2]);
	return (false);
}

bool	get_tex_colors(t_data *data, char *str, int i)
{
	while (i++ < 6)
	{
		if (ft_strncmp(data->mapinfo.file[i], str, 2) == 0)
		{
			if (ft_strncmp(str, "C", 1) == 0)
			{
				data->texinfo.ceiling = (int *)malloc(sizeof(int) * 3);
				if (data->texinfo.ceiling == NULL)
					return (ft_putendl_fd("Error\nmalloc error", 2), true);
				else
					return (copy_tex_colors(data->texinfo.ceiling
							, ft_split(&data->mapinfo.file[i][2], ',')));
			}
			else if (ft_strncmp(str, "F", 1) == 0)
			{
				data->texinfo.floor = (int *)malloc(sizeof(int) * 3);
				if (data->texinfo.ceiling == NULL)
					return (ft_putendl_fd("Error\nmalloc error", 2), true);
				else
					return (copy_tex_colors(data->texinfo.floor
							, ft_split(&data->mapinfo.file[i][2], ',')));
			}
		}
	}
	return (ft_printf("Error\n%s not found", str), true);
}

bool	get_color_hex(t_data *data, int *rgb, char c)
{
	int	r;
	int	g;
	int	b;

	r = rgb[0];
	b = rgb[1];
	g = rgb[2];
	if (c == 'C')
		data->texinfo.hex_ceiling = ((r & 0xff) << 16)
			+ ((b & 0xff) << 8) + (g & 0xff);
	else if (c == 'F')
		data->texinfo.hex_floor = ((r & 0xff) << 16)
			+ ((b & 0xff) << 8) + (g & 0xff);
	return (false);
}

size_t	arr_len(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}
