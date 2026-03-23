/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:45:22 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/23 19:00:26 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_imgs_type(t_textures **imgs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (imgs[i] && imgs[i]->type)
	{
		if (is_img(imgs[i]->type) != 0)
			return (ft_putendl_fd("Invalid texture identifier.", 1), 1);
		i++;
	}
	i = 0;
	while (imgs[i] && imgs[i]->type)
	{
		while (imgs[j] && imgs[j]->type)
		{
			if (ft_strncmp(imgs[j]->type, imgs[i]->type, 3) == 0 && i != j)
				return (ft_putendl_fd("Duplicate texture identifiers.", 1), 1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_textures(t_data *data)
{
	int	i;
	int	fd_2;

	i = 0;
	while (data->imgs[i] && data->imgs[i]->path)
	{
		fd_2 = open(data->imgs[i]->path, O_RDONLY);
		if (fd_2 == -1)
			return (ft_putendl_fd("Can not open texture.", 1), 1);
		close(fd_2);
		i++;
	}
	if (check_imgs_type(data->imgs) != 0)
		return (1);
	return (0);
}
int	check_colors_type(t_textures **imgs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (imgs[i] && imgs[i]->type)
	{
		if (is_color(imgs[i]->type) != 0)
			return (ft_putendl_fd("Invalid color identifier.", 1), 1);
		i++;
	}
	i = 0;
	while (imgs[i] && imgs[i]->type)
	{
		while (imgs[j] && imgs[j]->type)
		{
			if (ft_strncmp(imgs[j]->type, imgs[i]->type, 2) == 0 && i != j)
				return (ft_putendl_fd("Duplicate color identifiers.", 1),
					1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
int	check_colors(t_data *data)
{
	int i;

	i = 0;
	if (check_colors_type(data->colors) != 0)
		return (1);
	while (data->ceiling[i] && data->floor[i])
	{
		if (data->ceiling[i] < 0 || data->ceiling[i] > 255 || data->floor[i] < 0
			|| data->floor[i] > 255)
			return (ft_putendl_fd("Colors out of range", 1), 1);
		i++;
	}
	return (0);
}