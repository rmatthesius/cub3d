/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatthes <rmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:59:03 by rmatthes          #+#    #+#             */
/*   Updated: 2024/10/24 17:00:34 by rmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_w_key(t_data *data)
{
	if (data->map[(int)data->player.pos_y]
		[(int)(data->player.pos_x + data->player.dir_x * MOVESPEED)] == '0')
		data->player.pos_x += data->player.dir_x * MOVESPEED;
	if (data->map[(int)(data->player.pos_y + data->player.dir_y * MOVESPEED)]
		[(int)data->player.pos_x] == '0')
		data->player.pos_y += data->player.dir_y * MOVESPEED;
}

void	ft_s_key(t_data *data)
{
	if (data->map[(int)data->player.pos_y]
		[(int)(data->player.pos_x - data->player.dir_x * MOVESPEED)] == '0')
		data->player.pos_x -= data->player.dir_x * MOVESPEED;
	if (data->map[(int)(data->player.pos_y - data->player.dir_y * MOVESPEED)]
		[(int)data->player.pos_x] == '0')
		data->player.pos_y -= data->player.dir_y * MOVESPEED;
}

void	ft_a_key(t_data *data)
{
	double	move_x;
	double	move_y;

	move_x = data->player.dir_y * MOVESPEED;
	move_y = -data->player.dir_x * MOVESPEED;
	if (data->map[(int)(data->player.pos_y + move_y)]
		[(int)data->player.pos_x] == '0')
		data->player.pos_y += move_y;
	if (data->map[(int)data->player.pos_y]
		[(int)(data->player.pos_x + move_x)] == '0')
		data->player.pos_x += move_x;
}

void	ft_d_key(t_data *data)
{
	double	move_x;
	double	move_y;

	move_x = -data->player.dir_y * MOVESPEED;
	move_y = data->player.dir_x * MOVESPEED;
	if (data->map[(int)(data->player.pos_y + move_y)]
		[(int)data->player.pos_x] == '0')
		data->player.pos_y += move_y;
	if (data->map[(int)data->player.pos_y]
		[(int)(data->player.pos_x + move_x)] == '0')
		data->player.pos_x += move_x;
}

int	ft_game_loop(t_data *data)
{
	if (data->player.move_x == 1)
		ft_w_key(data);
	if (data->player.move_x == 2)
		ft_s_key(data);
	if (data->player.move_y == 1)
		ft_a_key(data);
	if (data->player.move_y == 2)
		ft_d_key(data);
	if (data->player.rotate == 1)
		ft_left_key(data);
	if (data->player.rotate == 2)
		ft_right_key(data);
	render_images(data);
	return (0);
}
