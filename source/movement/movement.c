/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatthes <rmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:33:42 by rmatthes          #+#    #+#             */
/*   Updated: 2024/10/24 17:00:30 by rmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_left_key(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x
		* cos(-ROTSPEED) - data->player.dir_y * sin(-ROTSPEED);
	data->player.dir_y = old_dir_x
		* sin(-ROTSPEED) + data->player.dir_y * cos(-ROTSPEED);
	data->player.plane_x = data->player.plane_x
		* cos(-ROTSPEED) - data->player.plane_y * sin(-ROTSPEED);
	data->player.plane_y = old_plane_x
		* sin(-ROTSPEED) + data->player.plane_y * cos(-ROTSPEED);
}

void	ft_right_key(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x
		* cos(ROTSPEED) - data->player.dir_y * sin(ROTSPEED);
	data->player.dir_y = old_dir_x
		* sin(ROTSPEED) + data->player.dir_y * cos(ROTSPEED);
	data->player.plane_x = data->player.plane_x
		* cos(ROTSPEED) - data->player.plane_y * sin(ROTSPEED);
	data->player.plane_y = old_plane_x
		* sin(ROTSPEED) + data->player.plane_y * cos(ROTSPEED);
}

int	ft_key_release(int keycode, t_data *data)
{
	if (keycode == 65307)
		on_destroy(data);
	if (keycode == 119)
		data->player.move_x = 0;
	if (keycode == 115)
		data->player.move_x = 0;
	if (keycode == 97)
		data->player.move_y = 0;
	if (keycode == 100)
		data->player.move_y = 0;
	if (keycode == 65361)
		data->player.rotate = 0;
	if (keycode == 65363)
		data->player.rotate = 0;
	return (0);
}

int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
		on_destroy(data);
	if (keycode == 119)
		data->player.move_x = 1;
	if (keycode == 115)
		data->player.move_x = 2;
	if (keycode == 97)
		data->player.move_y = 1;
	if (keycode == 100)
		data->player.move_y = 2;
	if (keycode == 65361)
		data->player.rotate = 1;
	if (keycode == 65363)
		data->player.rotate = 2;
	return (0);
}

void	mlx_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 1L << 17, &on_destroy, data);
	mlx_hook(data->win, 12, 1L << 15, &on_maximize, data);
	mlx_hook(data->win, 2, 1L << 0, ft_key_press, data);
	mlx_hook(data->win, 3, 1L << 1, ft_key_release, data);
	mlx_loop_hook(data->mlx, &ft_game_loop, data);
}
