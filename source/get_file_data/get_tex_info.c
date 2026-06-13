/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:27:10 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/22 14:32:15 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	get_texinfo(t_data *data)
{
	if (get_tex_paths(data, "NO "))
		return (true);
	if (get_tex_paths(data, "SO "))
		return (true);
	if (get_tex_paths(data, "WE "))
		return (true);
	if (get_tex_paths(data, "EA "))
		return (true);
	if (check_tex_paths(data))
		return (true);
	if (get_tex_colors(data, "C ", 0))
		return (true);
	if (get_tex_colors(data, "F ", 0))
		return (true);
	if (check_colors(data))
		return (true);
	if (get_color_hex(data, data->texinfo.ceiling, 'C'))
		return (true);
	if (get_color_hex(data, data->texinfo.floor, 'F'))
		return (true);
	return (false);
}
