/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatthes <rmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:10:36 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/24 18:02:47 by rmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_texinfo(t_texinfo *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = 0;
	textures->ceiling = 0;
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->size = TEX_SIZE;
	textures->step = 0.0;
	textures->pos = 0.0;
	textures->x = 0;
	textures->y = 0;
}

bool	init_tex_img(t_data *data, t_img *img, char *path)
{
	init_img_clean(img);
	img->img = mlx_xpm_file_to_image(data->mlx,
			path, &data->texinfo.size, &data->texinfo.size);
	if (img->img == NULL)
		return (ft_putendl_fd("Error /nCan't tranform xpm to img", 2), true);
	img->addr = (int *)mlx_get_data_addr(img->img,
			&img->pixel_bits, &img->size_line, &img->endian);
	if (img->addr == NULL)
		return (ft_putendl_fd("Error /nCan't tranform xpm to img", 2),
			mlx_destroy_image(data->mlx, img->img), true);
	return (false);
}

int	*xpm_to_img(t_data *data, char *path, int i, int *buffer)
{
	t_img	tmp;
	int		j;

	if (init_tex_img(data, &tmp, path))
		return (NULL);
	buffer = malloc(1 * sizeof(*buffer)
			* data->texinfo.size * data->texinfo.size);
	if (buffer != NULL)
		memset(buffer, 0, sizeof(*buffer)
			* data->texinfo.size * data->texinfo.size);
	else
		return (ft_putendl_fd("Error\nmalloc error", 2), NULL);
	while (i < data->texinfo.size)
	{
		j = 0;
		while (j < data->texinfo.size)
		{
			buffer[i * data->texinfo.size
				+ j] = tmp.addr[i * data->texinfo.size + j];
			++j;
		}
		i++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

bool	init_textures(t_data *data)
{
	data->textures = (int **)malloc(sizeof(int *) * 5);
	if (data->textures == NULL)
		return (ft_putendl_fd("Error\nmalloc error", 2), true);
	data->textures[0] = xpm_to_img(data, data->texinfo.north, 0, NULL);
	if (data->textures[0] == NULL)
		return (true);
	data->textures[1] = xpm_to_img(data, data->texinfo.south, 0, NULL);
	if (data->textures[1] == NULL)
		return (true);
	data->textures[2] = xpm_to_img(data, data->texinfo.east, 0, NULL);
	if (data->textures[2] == NULL)
		return (true);
	data->textures[3] = xpm_to_img(data, data->texinfo.west, 0, NULL);
	if (data->textures[3] == NULL)
		return (true);
	data->textures[4] = NULL;
	return (false);
}
