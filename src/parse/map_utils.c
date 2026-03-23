/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:16:43 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/23 18:41:40 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_count_spaces(char *str, int flag)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i] == ' ')
		i++;
	if (flag == 0)
		return (i);
	else if (flag == 1)
	{
		while (str[i])
			i++;
		i--;
		while (str[i] == ' ')
		{
			i--;
			ret++;
		}
	}
	return (ret);
}

int	ft_count_ones(char *str, int flag)
{
	int	i;
	int	ret;

	i = ft_count_spaces(str, flag);
	ret = 0;
	while (str[i] == '1')
		i++;
	if (flag == 0)
		return (i);
	else if (flag == 1)
	{
		while (str[i])
			i++;
		i -= ft_count_spaces(str, flag) + 1;
		while (str[i] == '1')
		{
			i--;
			ret++;
		}
	}
	return (ret);
}

int	is_valid_char(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'O' && c != 'W' && c != 'S')
		return (1);
	return (0);
}
int	is_safe(char **map, int i, int j)
{
	if (j == 0)
		return (1);
	if ((j >= (int)ft_strlen(map[i + 1])) || (j >= (int)ft_strlen(map[i - 1])))
		return (1);
	if (is_valid_char(map[i + 1][j]) == 1 || is_valid_char(map[i - 1][j]) == 1
		|| is_valid_char(map[i][j + 1]) == 1 || is_valid_char(map[i][j
			- 1]) == 1)
		return (1);
	return (0);
}
int	check_zeros(char **map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '0' && is_safe(map, i, j) == 1)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
