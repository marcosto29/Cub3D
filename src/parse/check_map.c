/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:48:57 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/19 19:05:46 by aosset-o         ###   ########.fr       */
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
				return (ft_putendl_fd("Error\nInvalid map.", 1), 1);
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count != 1)
		return (ft_putendl_fd("Error\nInvalid map.", 1), 1);
	return (0);
}

int	check_first_last(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i] != ' ' && data->map[0][i] != '1')
			return (ft_putendl_fd("Error\nInvalid map.", 1), 1);
		i++;
	}
	i = 0;
	while (data->map[data->map_len - 1][i])
	{
		if (data->map[data->map_len - 1][i] != ' ' && data->map[data->map_len
			- 1][i] != '1')
			return (ft_putendl_fd("Error\nInvalid map.", 1), 1);
		i++;
	}
	return (0);
}

int	check_map(t_data *data)
{
	if (check_chars(data->map) != 0 || check_first_last(data) != 0)
		return (1);
	return (0);
}