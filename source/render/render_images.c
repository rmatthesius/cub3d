/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatthes <rmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:05:09 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/24 17:50:13 by rmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	init_tex_pix(t_data *data)
{
	int	i;

	i = 0;
	if (data->texture_pixels)
		ft_free_int_arr(data->texture_pixels);
	data->texture_pixels = ft_calloc(data->win_height + 1,
			sizeof * data->texture_pixels);
	if (data->texture_pixels == NULL)
		return (ft_putendl_fd("Error\nmalloc error", 2), true);
	while (i < data->win_height)
	{
		data->texture_pixels[i] = ft_calloc(data->win_width + 1,
				sizeof * data->texture_pixels);
		if (data->texture_pixels[i] == NULL)
			return (ft_putendl_fd("Error\nmalloc error", 2), true);
		i++;
	}
	data->texture_pixels[i] = NULL;
	return (false);
}

void	set_frame_image_pixel(t_data *data, t_img *image, int x, int y)
{
	int	pixel;

	pixel = 0;
	if (data->texture_pixels[y][x] > 0)
	{
		pixel = y * (image->size_line / 4) + x;
		image->addr[pixel] = data->texture_pixels[y][x];
	}
	else if (y < data->win_height / 2)
	{
		pixel = y * (image->size_line / 4) + x;
		image->addr[pixel] = data->texinfo.hex_ceiling;
	}
	else if (y < data->win_height -1)
	{
		pixel = y * (image->size_line / 4) + x;
		image->addr[pixel] = data->texinfo.hex_floor;
	}
}

bool	init_img(t_data *data, t_img *image, int width, int height)
{
	init_img_clean(image);
	image->img = mlx_new_image(data->mlx, width, height);
	if (image->img == NULL)
		return (ft_putendl_fd("Error\nmalloc error", 2), true);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	if (image->addr == NULL)
		return (ft_putendl_fd("Error\nget addr", 2), true);
	return (false);
}

bool	render_frame(t_data *data)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_img(data, &image, data->win_width, data->win_height);
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			set_frame_image_pixel(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, image.img, 0, 0);
	mlx_destroy_image(data->mlx, image.img);
	return (false);
}

bool	render_images(t_data *data)
{
	init_tex_pix(data);
	init_ray(&data->ray);
	raycasting(&data->player, data);
	render_frame(data);
	return (false);
}
