/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:01:33 by jkarras           #+#    #+#             */
/*   Updated: 2024/11/04 13:54:18 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ft_putendl_fd("Error\nmlx init error", 2), true);
	data->win = mlx_new_window(data->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Ape trouble 3D");
	if (data->win == NULL)
		return (ft_putendl_fd("Error\nmlx window init error", 2), true);
	return (false);
}
