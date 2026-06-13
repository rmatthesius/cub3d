/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatthes <rmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:42:24 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/24 17:33:10 by rmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	set_file_info(t_data *data, char *path)
{
	int		fd2;
	int		count;
	char	*line;

	data->mapinfo.fd = open(path, O_RDONLY);
	if (data->mapinfo.fd < 0)
		return (ft_putendl_fd("Error\ncan't open file", 2), true);
	data->mapinfo.path = ft_strdup(path);
	if (data->mapinfo.path == NULL)
		return (ft_putendl_fd("Error\nmalloc error", 2), true);
	fd2 = open (path, O_RDONLY);
	if (fd2 < 0)
		return (ft_putendl_fd("Error\ncan't open file", 2), true);
	count = 0;
	line = get_next_line(fd2);
	while (line)
	{
		free(line);
		line = get_next_line(fd2);
		count++;
	}
	if (count < 9)
		return (close(fd2), ft_putendl_fd("Error\nfile to small", 2), true);
	data->mapinfo.line_count = count;
	return (close(fd2), false);
}

bool	get_file(t_data *data)
{
	int	i;

	data->mapinfo.file = (char **)malloc(sizeof(char *)
			* (data->mapinfo.line_count + 1));
	if (data->mapinfo.file == NULL)
		return (ft_putendl_fd("Error\nmalloc error", 2), true);
	i = 0;
	while (i < data->mapinfo.line_count)
	{
		data->mapinfo.file[i] = get_next_line(data->mapinfo.fd);
		i++;
	}
	data->mapinfo.file[i] = NULL;
	return (false);
}

bool	parse_args(t_data *data, char *path)
{
	if (check_arg(path))
		return (true);
	if (set_file_info(data, path))
		return (true);
	if (get_file(data))
		return (true);
	return (false);
}
