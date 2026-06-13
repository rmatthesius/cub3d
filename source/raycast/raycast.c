/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatthes <rmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:18:10 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/28 13:18:20 by rmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// Funktion zur Initialisierung des DDA-Verfahrens
// (Digital Differential Analyzer)
// if/else Bestimme die Richtung und Startdistanz
// entlang der XY-Achse
// Wenn die Richtung des Strahls nach links zeigt
// Strahl Schrittweise nach links bewegen
// dann, berechne die Entfernung von der Spielerposition
// zur ersten X-seitenlinie
void	set_dda(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

// Funktion zur Durchfuerung des DDA-Alogritmus, um Wandkolisionen zu finden
// hit = 0; Trefferindikator, = 0 keine Wandgetroffen
// Pruefung in welche Richtung der Strahl weitergehen soll
// Falls die X-Distanz groesser ist gehe in diese richtung
// andern falls in Y-Richtung
// Erhoehe die Distanz zur naechsten Seitenlinie
// Aktualliesiere die Position auf dem Raster
// ray->side = 0 steht fuer Kollision auf einer vertikalen Wand
// ray->side = 1 steht fuer Kollision auf einer horizontalen Wand
void	perform_dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25
			|| ray->map_x < 0.25
			|| ray->map_y > data->mapinfo.height - 0.25
			|| ray->map_x > data->mapinfo.width - 1.25)
			break ;
		else if (data->map[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}
}

void	get_texture_index(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			data->texinfo.index = 3;
		else
			data->texinfo.index = 2;
	}
	else
	{
		if (ray->dir_y > 0)
			data->texinfo.index = 1;
		else
			data->texinfo.index = 0;
	}
}

void	update_texture_pixels(t_data *data, t_texinfo *tex, t_ray *ray, int x)
{
	int			y;
	int			color;

	get_texture_index(data, ray);
	tex->x = (int)(ray->wall_x * tex->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	tex->pos = (ray->draw_start - data->win_height / 2
			+ ray->line_height / 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = data->textures[tex->index][tex->size * tex->y + tex->x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->texture_pixels[y][x] = color;
		y++;
	}
}

bool	raycasting(t_player *player, t_data *data)
{
	t_ray	ray;
	int		i;

	i = 0;
	ray = data->ray;
	while (i < data->win_width)
	{
		init_raycasting_info(i, &ray, player);
		set_dda(&ray, player);
		perform_dda(data, &ray);
		calculate_line_height(&ray, data, player);
		update_texture_pixels(data, &data->texinfo, &ray, i);
		i++;
	}
	return (false);
}
