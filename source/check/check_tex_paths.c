/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tex_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:59:11 by jkarras           #+#    #+#             */
/*   Updated: 2024/11/04 13:54:18 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	check_tex_paths(t_data *data)
{
	if (is_xpm_file(data->texinfo.north))
		return (ft_putendl_fd("Error\nnorth is no xpm file", 2), true);
	if (is_xpm_file(data->texinfo.south))
		return (ft_putendl_fd("Error\nsouth is no xpm file", 2), true);
	if (is_xpm_file(data->texinfo.east))
		return (ft_putendl_fd("Error\neast is no xpm file", 2), true);
	if (is_xpm_file(data->texinfo.west))
		return (ft_putendl_fd("Error\nwest is no xpm file", 2), true);
	if (n_exist(data->texinfo.north))
		return (ft_putendl_fd("Error\nnorth not exist", 2), true);
	if (n_exist(data->texinfo.south))
		return (ft_putendl_fd("Error\nsouth not exist", 2), true);
	if (n_exist(data->texinfo.east))
		return (ft_putendl_fd("Error\neast not exist", 2), true);
	if (n_exist(data->texinfo.west))
		return (ft_putendl_fd("Error\nwest not exist", 2), true);
	if (is_dir(data->texinfo.north))
		return (ft_putendl_fd("Error\nnorth is dir", 2), true);
	if (is_dir(data->texinfo.south))
		return (ft_putendl_fd("Error\nsouth is dir", 2), true);
	if (is_dir(data->texinfo.east))
		return (ft_putendl_fd("Error\neast is dir", 2), true);
	if (is_dir(data->texinfo.west))
		return (ft_putendl_fd("Error\nwest is dir", 2), true);
	return (false);
}
