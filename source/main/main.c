/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:17:59 by jkarras           #+#    #+#             */
/*   Updated: 2024/11/04 13:53:58 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_data2(t_data *data)
{
	if (data->texinfo.north)
		free(data->texinfo.north);
	if (data->texinfo.south)
		free(data->texinfo.south);
	if (data->texinfo.east)
		free(data->texinfo.east);
	if (data->texinfo.west)
		free(data->texinfo.west);
	if (data->texinfo.floor)
		free(data->texinfo.floor);
	if (data->texinfo.ceiling)
		free(data->texinfo.ceiling);
	if (data->win)
	{
		mlx_destroy_display(data->mlx);
		mlx_destroy_window(data->mlx, data->win);
	}
	if (data->mlx)
		free(data->mlx);
}

void	free_data(t_data *data)
{
	if (data->mapinfo.fd)
		close(data->mapinfo.fd);
	if (data->mapinfo.path)
		free(data->mapinfo.path);
	if (data->mapinfo.file)
		ft_freechar_array(data->mapinfo.file);
	if (data->map)
		ft_freechar_array(data->map);
	if (data->texture_pixels)
		ft_free_int_arr(data->texture_pixels);
	if (data->textures)
		ft_free_int_arr(data->textures);
	free_data2(data);
}

int	on_destroy(t_data *data)
{
	free_data(data);
	exit(0);
}

int	on_maximize(t_data *data)
{
	ft_putendl_fd(data->texinfo.north, 2);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_putendl_fd("Error\nWrong arg number", 2), 1);
	init_data(&data);
	if (parse_args(&data, argv[1]))
		return (1);
	if (clean_file(&data))
		return (1);
	if (get_file_data(&data))
		return (1);
	if (init_mlx(&data))
		return (1);
	init_textures(&data);
	render_images(&data);
	data.map[(int)data.player.pos_y][(int)data.player.pos_x] = '0';
	mlx_hooks(&data);
	mlx_loop(data.mlx);
}

	// mlx_hook(game.window.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	// mlx_hook(game.window.win, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
	// mlx_hook(game.window.win, X_EVENT_EXIT, 0, &exit_hook, &game);
	// mlx_loop_hook(game.window.ptr, &main_loop, &game);
	// mlx_loop(game.window.ptr);
