/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:44:41 by jkarras           #+#    #+#             */
/*   Updated: 2024/11/04 13:54:18 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	is_dir(char *path)
{
	int	fd;

	fd = open(path, __O_DIRECTORY);
	if (fd >= 0)
		return (close (fd), true);
	return (false);
}

bool	n_exist(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (true);
	return (close(fd), false);
}

bool	check_arg(char *path)
{
	if (n_exist(path))
		return (ft_putendl_fd("Error\ncan't open file", 2), true);
	if (is_dir(path))
		return (ft_putendl_fd("Error\nis dir", 2), true);
	if (is_cub_file(path))
		return (ft_putendl_fd("Error\nno .cub file", 2), true);
	return (false);
}
