/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatthes <rmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:28:38 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/28 13:28:54 by rmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_raycasting_info(int i, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->camera_x = 2 * i / (double)WINDOW_WIDTH -1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

// Berechne die Hoehe und Position der Wandlinie
// Berechne die Entfernung zur Wand abhaenig von der getroffenen Seite
// Wenn eine vertikale Wand getroffen wurde, basiert die Distanz auf X
// bei einer horizontalen Wand auf Y Richtung
// Berechne die Hoehe der Linie, die die Wand darstellen soll
// Berechne die Anfangsposition der Linie im Fenster
// Falls die Startposition ueber dem Fensteranfang liegt,
// setze sie auf den oberen Rand
// Berechne die Endposition der Linie im Fenster
// Falls die Startposition unterhalb dem Fensteranfang liebt,
// setze sie auf den unteren Rand
// Berechne den exakten X-Kollisionspunkt an der Wand, um auf der Y-Position
// des Spielers
// Falls es eine vertikale Wand ist,
// basiert der Kollisionspunkt auf der Y-Position
// Falls es eine horizontale Wand ist,
// basiert der Kollisionspunkt auf der X-Position
// Als letztes Entferne die Ganzzahlanteile des Kollisionspunktes,
// um die exakte Texturenkoordinate zu erhalten
void	calculate_line_height(t_ray *ray, t_data *data, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(data->win_height / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + data->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->win_height / 2;
	if (ray->draw_end >= data->win_height)
		ray->draw_end = data->win_height - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}
