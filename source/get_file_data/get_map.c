/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:34:16 by jkarras           #+#    #+#             */
/*   Updated: 2024/11/04 13:54:18 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_biggest_len(t_data *data)
{
	int		i;
	char	*line;
	size_t	len;

	i = 6;
	len = 0;
	while (data->mapinfo.file[i])
	{
		line = data->mapinfo.file[i];
		if (len < ft_strlen(line))
			len = ft_strlen(line);
		i++;
	}
	data->mapinfo.width = (int)len;
}

void	get_height(t_data *data)
{
	int	i;
	int	height;

	i = 6;
	height = 0;
	while (data->mapinfo.file[i])
	{
		if (is_empty(data->mapinfo.file[i]))
			break ;
		height++;
		i++;
	}
	data->mapinfo.height = height;
	data->mapinfo.index_end_of_map = i - 6;
}

bool	get_map_dim(t_data *data)
{
	get_biggest_len(data);
	if (data->mapinfo.width < 3)
		return (ft_putendl_fd("Error\nmap width to small", 2), true);
	get_height(data);
	if (data->mapinfo.width < 3)
		return (ft_putendl_fd("Error\nmap width to small", 2), true);
	return (false);
}

bool	get_map(t_data *data)
{
	int	i;
	int	j;

	i = 6;
	j = 0;
	data->map = (char **)malloc(sizeof(char *) * (data->mapinfo.height + 1));
	if (data->map == NULL)
		return (ft_putendl_fd("Error\nmalloc error", 2), true);
	while (j != data->mapinfo.index_end_of_map)
	{
		data->map[j] = ft_strdup(data->mapinfo.file[i]);
		if (data->map[j] == NULL)
			return (ft_putendl_fd("Error\nmalloc error", 2), true);
		j++;
		i++;
	}
	data->map[j] = 0;
	return (false);
}
