/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatthes <rmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:06:48 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/24 17:07:00 by rmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	is_negativ(int *arr)
{
	if (arr[0] < 0)
		return (true);
	if (arr[1] < 0)
		return (true);
	if (arr[2] < 0)
		return (true);
	return (false);
}

bool	is_to_big(int *arr)
{
	if (arr[0] > 255)
		return (true);
	if (arr[1] > 255)
		return (true);
	if (arr[2] > 255)
		return (true);
	return (false);
}

bool	check_colors(t_data *data)
{
	if (is_negativ(data->texinfo.ceiling))
	{
		ft_putendl_fd("Error", 2);
		return (ft_putendl_fd("color in celing is negativ", 2), true);
	}
	if (is_negativ(data->texinfo.floor))
	{
		ft_putendl_fd("Error", 2);
		return (ft_putendl_fd("color in floor is negativ", 2), true);
	}
	if (is_to_big(data->texinfo.ceiling))
	{
		ft_putendl_fd("Error", 2);
		return (ft_putendl_fd("color in celing is greater than 255", 2), true);
	}
	if (is_to_big(data->texinfo.floor))
	{
		ft_putendl_fd("Error", 2);
		return (ft_putendl_fd("color in floor is greater than 255", 2), true);
	}
	return (false);
}
