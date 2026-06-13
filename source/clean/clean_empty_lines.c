/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_empty_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatthes <rmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:15:27 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/24 17:21:08 by rmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

void	remove_line(t_data *data, int i)
{
	int	j;

	if (data->mapinfo.file[i])
		free(data->mapinfo.file[i]);
	j = i;
	while (data->mapinfo.file[j])
	{
		data->mapinfo.file[j] = data->mapinfo.file[j + 1];
		j++;
	}
	data->mapinfo.file[j] = NULL;
}

void	remove_empty_lines_above_map(t_data *data)
{
	int	i;

	i = 6;
	while (data->mapinfo.file[i])
	{
		if (is_empty(data->mapinfo.file[i]))
		{
			remove_line(data, i);
			i = 6;
		}
		else
			break ;
	}
}

bool	clean_empty_lines(t_data *data)
{
	int	i;

	i = 0;
	while (data->mapinfo.file[i] && i < 6)
	{
		if (is_empty(data->mapinfo.file[i]))
		{
			remove_line(data, i);
			i = 0;
		}
		i++;
	}
	remove_empty_lines_above_map(data);
	return (false);
}
