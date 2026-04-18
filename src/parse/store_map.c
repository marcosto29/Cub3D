/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:24:16 by aosset-o          #+#    #+#             */
/*   Updated: 2026/04/02 14:01:23 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	store_splitted(char *str, t_data *data, int *pos_img, int *pos_clr)
{
	char **args;

	if (!str)
		return (1);
	args = ft_split(str, ' ');
	if (!args)
		return (1);
	if(args[0] && args[1] && !is_img(args[0]))
	{
		if (*pos_img >= data->img_len)
			return (free_double(args), 1);
		data->imgs[*pos_img]->type = ft_strdup(args[0]);
		data->imgs[*pos_img]->path = ft_strtrim(args[1], "\n");
		(*pos_img)++;
	}
	else if(args[0] && args[1] && !is_color(args[0]))
	{
		if (*pos_clr >= data->clr_len)
			return (free_double(args), 1);
		data->colors[*pos_clr]->type = ft_strdup(args[0]);
		data->colors[*pos_clr]->path = ft_strtrim(args[1], "\n");
		(*pos_clr)++;
	}
	free_double(args);
	return (0);
}

int	store_elements(int fd, t_data *data, char **aux)
{
	int pos_img;
	int pos_clr;
	int i;
	int len;

	pos_img = 0;
	pos_clr = 0;
	len = data->img_len + data->clr_len;
	i = 0;
	while (i < len)
	{
		*aux = skip_empty(*aux, fd);
		if (store_splitted(*aux, data, &pos_img, &pos_clr) != 0)
			return (1);
		free(*aux);
		*aux = get_next_line(fd);
		i++;
	}
	return (0);
}

void	colors_int(t_textures *colors, t_data *data, char c)
{
	char	**splitted_colors;
	int		i;

	if (c != 'C' && c != 'F')
	{
		data->floor[0] = -1;
		data->ceiling[0] = -1;
		return ;
	}
	i = 0;
	splitted_colors = ft_split(colors->path, ',');
	while (splitted_colors[i] && i < 3)
	{
		if (c == 'F')
			data->floor[i] = ft_atoi(splitted_colors[i]);
		else if (c == 'C')
			data->ceiling[i] = ft_atoi(splitted_colors[i]);
		i++;
	}
	if (splitted_colors[3])
	{
		data->floor[0] = -1;
		data->ceiling[0] = -1;
	}
	free_double(splitted_colors);
}

char	*store_map(char **map, char *aux, int fd)
{
	int	i;

	i = 0;
	while (aux && aux[0] != '\n')
	{
		map[i] = ft_strtrim(aux, "\n");
		free(aux);
		aux = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (aux);
}

void	read_map(t_data *data, int fd)
{
	char	*aux;
	int		failed_elements;

	aux = get_next_line(fd);
	failed_elements = store_elements(fd, data, &aux);
	if (failed_elements != 0)
	{
		data->floor[0] = -1;
		data->ceiling[0] = -1;
	}
	aux = skip_empty(aux, fd);
	aux = store_map(data->map, aux, fd);
	if (data->colors[0]->path && data->colors[1]->path)
	{
		colors_int(data->colors[0], data, data->colors[0]->type[0]);
		colors_int(data->colors[1], data, data->colors[1]->type[0]);
	}
	if (aux)
		free(aux);
	get_next_line(-1);
}
