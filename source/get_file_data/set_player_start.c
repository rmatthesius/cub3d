/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatthes <rmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:53:24 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/24 17:22:51 by rmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	set_dir_plane_n_s(t_data *data)
{
	if (data->player.dir == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
		data->player.plane_x = -0.66;
		data->player.plane_y = 0;
	}
	else if (data->player.dir == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
		data->player.plane_x = 0.66;
		data->player.plane_y = 0;
	}
}

void	set_dir_plane_w_e(t_data *data)
{
	if (data->player.dir == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = -0.66;
	}
	else if (data->player.dir == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = 0.66;
	}
}

void	set_player_start_pos(t_data *data, int y, int x)
{
	data->player.dir = data->map[y][x];
	data->player.pos_x = (double)x + 0.5;
	data->player.pos_y = (double)y + 0.5;
	if (data->map[y][x] == 'N' || data->map[y][x] == 'S')
		set_dir_plane_n_s(data);
	else
		set_dir_plane_w_e(data);
}
