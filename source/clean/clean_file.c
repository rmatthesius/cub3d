/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatthes <rmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:27:15 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/24 17:21:21 by rmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	clean_spaces(t_data *data)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (data->mapinfo.file[i] && i < 6)
	{
		line = data->mapinfo.file[i];
		j = 0;
		while (line[j])
		{
			if (line[j] == ' ' && line[j + 1] == ' ')
				ft_memmove(&line[j], &line[j + 1], ft_strlen(&line[j + 1]) + 1);
			else
				j++;
		}
		i++;
	}
	return (false);
}

bool	clean_new_lines(t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	while (data->mapinfo.file[i])
	{
		if (i < 6)
			tmp = ft_strtrim(data->mapinfo.file[i], "\n ");
		else
			tmp = ft_strtrim(data->mapinfo.file[i], "\n");
		if (tmp == NULL)
			return (true);
		free(data->mapinfo.file[i]);
		data->mapinfo.file[i] = tmp;
		i++;
	}
	return (false);
}

bool	clean_file(t_data *data)
{
	if (clean_empty_lines(data))
		return (true);
	if (clean_new_lines(data))
		return (true);
	if (clean_spaces(data))
		return (true);
	return (false);
}
