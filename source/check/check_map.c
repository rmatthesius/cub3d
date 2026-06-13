/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:36:24 by jkarras           #+#    #+#             */
/*   Updated: 2024/11/04 13:54:18 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	check_wrong_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'N'
				&& map[i][j] != 'W'
				&& map[i][j] != 'E'
				&& map[i][j] != 'S'
				&& map[i][j] != '0'
				&& map[i][j] != '1'
				&& map[i][j] != ' ')
				return (ft_putendl_fd("Error\nwrong char in map", 2), true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	check_start_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'S')
				return (set_player_start_pos(data, i, j), false);
			j++;
		}
		i++;
	}
	return (ft_putendl_fd("Error\nno start pos found", 2), true);
}

bool	check_after_map(t_data *data)
{
	size_t	i;

	i = data->mapinfo.index_end_of_map + 6;
	while (data->mapinfo.file[i])
	{
		if (is_empty(data->mapinfo.file[i]))
			i++;
		else
			return (ft_putendl_fd("Error\nmap is not last", 2), true);
	}
	return (false);
}

bool	check_multiple_start_pos(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'S')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (ft_putendl_fd("Error\nmore than one start pos", 2), true);
	return (false);
}

bool	check_map(t_data *data)
{
	if (check_after_map(data))
		return (true);
	if (check_wrong_chars(data->map))
		return (true);
	if (check_start_pos(data))
		return (true);
	if (check_walls(data, 0))
		return (true);
	if (check_multiple_start_pos(data))
		return (true);
	return (false);
}
