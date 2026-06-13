/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatthes <rmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:09:31 by jkarras           #+#    #+#             */
/*   Updated: 2024/10/24 17:20:20 by rmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	fill_firs_last(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (i < data->mapinfo.width + 4)
	{
		str[i] = '1';
		i++;
	}
	str[i] = '\0';
}

void	fill_second_secondlast(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (i < data->mapinfo.width + 4)
	{
		if (i == 0 || i == data->mapinfo.width + 4 - 1)
			str[i] = '1';
		else
			str[i] = ' ';
		i++;
	}
	str[i] = '\0';
}

void	fill_middle(t_data *data, char *str, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (j < data->mapinfo.width + 4)
	{
		if (j == 0 || j == data->mapinfo.width + 4 - 1)
			str[j] = '1';
		else if (j == 1 || j == data->mapinfo.width + 4 - 2)
			str[j] = ' ';
		else if (data->map[i][k])
		{
			str[j] = data->map[i][k];
			k++;
		}
		else
			str[j] = ' ';
		j++;
	}
}

void	check_recrusiv(int x, int y, char **map, bool *error)
{
	if (x < 1 || y < 1 || map[y][x] == '1' || map[y][x] == 'v')
		return ;
	if (map[y][x] != ' ')
		*error = true;
	map[y][x] = 'v';
	check_recrusiv(x + 1, y, map, error);
	check_recrusiv(x - 1, y, map, error);
	check_recrusiv(x, y - 1, map, error);
	check_recrusiv(x, y + 1, map, error);
}

bool	check_walls(t_data *data, int i)
{
	char	**tmp;
	bool	flag;

	tmp = (char **)malloc(sizeof(char *) * (data->mapinfo.height + 5));
	if (tmp == NULL)
		return (true);
	while (i < data->mapinfo.height + 4)
	{
		tmp[i] = (char *)malloc(sizeof(char *) + (data->mapinfo.width + 5));
		if (tmp[i] == NULL)
			return (ft_freechar_array(tmp), ft_putendl_fd("Error", 2), true);
		if (i == 0 || i == data->mapinfo.height + 3)
			fill_firs_last(data, tmp[i]);
		else if (i == 1 || i == data->mapinfo.height + 2)
			fill_second_secondlast(data, tmp[i]);
		else
			fill_middle(data, tmp[i], i - 2);
		i++;
	}
	flag = false;
	check_recrusiv(1, 1, tmp, &flag);
	if (flag)
		return (ft_freechar_array(tmp)
			, ft_putendl_fd("Error\nmap is not surrounded", 2), true);
	return (check_spaces_in_map(tmp));
}
