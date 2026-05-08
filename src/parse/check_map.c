/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:48:57 by aosset-o          #+#    #+#             */
/*   Updated: 2026/05/08 14:59:32 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_chars(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_valid(map[i][j]) != 0)
				return (1);
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	check_first_last(t_data *data, t_parse *parse)
{
	int	i;

	i = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i] != ' ' && data->map[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (data->map[parse->map_len - 1][i])
	{
		if (data->map[parse->map_len - 1][i] != ' ' && data->map[parse->map_len
			- 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	is_position(char **map, int i, int j)
{
	if (is_valid_char(map[i + 1][j]) || is_valid_char(map[i - 1][j])
		|| is_valid_char(map[i][j + 1]) || is_valid_char(map[i][j - 1]))
		return (1);
	return (0);
}

int	check_position(char **map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
					|| map[i][j] == 'W') && is_position(map, i, j) == 1)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_map(t_data *data, t_parse *parse)
{
	int	i;

	if (check_chars(data->map) != 0 || check_first_last(data, parse) != 0
		|| check_zeros(data->map) != 0 || check_position(data->map) != 0)
		return (ft_putendl_fd("Invalid map.", 1), 1);
	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) < 1 || ft_strlen(data->map[i]) > 128)
			return (ft_putendl_fd("Invalid map.", 1), 1);
		i++;
	}
	return (0);
}
