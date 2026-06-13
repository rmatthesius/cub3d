/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:33:06 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/24 13:27:02 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	check_spaces_in_map(char **tmp)
{
	int	i;
	int	j;

	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == ' ')
			{
				ft_freechar_array(tmp);
				return (ft_putendl_fd("Error\nspace in map", 2), true);
			}
			j++;
		}
		i++;
	}
	ft_freechar_array(tmp);
	return (false);
}
