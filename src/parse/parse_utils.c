/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 09:24:13 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/23 19:07:13 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(char *av1)
{
	char	**split;

	split = ft_split(av1, '.');
	if (ft_strncmp(split[1], "cub", 4) != 0)
	{
		free_double(split);
		return (1);
	}
	free_double(split);
	return (0);
}

char	*skip_empty(char *aux, int fd)
{
	while (aux && aux[0] == '\n')
	{
		free(aux);
		aux = get_next_line(fd);
	}
	return (aux);
}

int	is_img(char *str)
{
	if (ft_strncmp(str, "NO", 3) != 0 && ft_strncmp(str, "SO", 3) != 0
		&& ft_strncmp(str, "WE", 3) != 0 && ft_strncmp(str, "EA", 3) != 0)
		return (1);
	return (0);
}

int	is_color(char *str)
{
	if (ft_strncmp(str, "C", 2) != 0 && ft_strncmp(str, "F", 2) != 0)
		return (1);
	return (0);
}

int	is_valid(char c)
{
	if (c != '1' && c != '0' && c != ' ' && c != 'N' && c != 'S' && c != 'E'
		&& c != 'W')
		return (1);
	return (0);
}
