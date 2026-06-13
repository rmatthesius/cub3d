/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_suffix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:00:50 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/22 14:00:58 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	is_xpm_file(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (path[len - 1] != 'm')
		return (true);
	else if (path[len - 2] != 'p')
		return (true);
	else if (path[len - 3] != 'x')
		return (true);
	else if (path[len - 4] != '.')
		return (true);
	return (false);
}

bool	is_cub_file(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (path[len - 1] != 'b')
		return (true);
	else if (path[len - 2] != 'u')
		return (true);
	else if (path[len - 3] != 'c')
		return (true);
	else if (path[len - 4] != '.')
		return (true);
	return (false);
}
