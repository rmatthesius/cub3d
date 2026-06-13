/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:45:52 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/22 14:36:18 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	get_file_data(t_data *data)
{
	if (get_texinfo(data))
		return (true);
	if (get_map_dim(data))
		return (true);
	if (get_map(data))
		return (true);
	if (check_map(data))
		return (true);
	return (false);
}
