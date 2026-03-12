/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_store.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:24:16 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/12 18:41:43 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*store_textures(int fd, t_textures **data, char *aux, int len)
{
	char	**args;
	int		i;

	i = 0;
	while (i < len && aux && aux[0] != '\n')
	{
		args = ft_split(aux, ' ');
		if (!args || !args[0] || !args[1])
		{
			ft_putendl_fd("textures does not exit.", 1);
			return (aux);
		}
		data[i]->type = ft_strdup(args[0]);
		data[i]->path = ft_strdup(args[1]);
		free(aux);
		free_double(args);
		aux = get_next_line(fd);
		i++;
	}
	return (aux);
}

void store_colors(t_textures *colors, t_data *data, char c)
{
    char **splitted_colors;
    int i;

	if(c != 'C' && c != 'F')
	{
		data->floor[0] = -1;
		data->ceiling[0] = -1;
		return;
	}
    i = 0;
    splitted_colors = ft_split(colors->path, ',');
    while (splitted_colors[i] && i < 3)
    {
        if(c == 'F')
            data->floor[i] = ft_atoi(splitted_colors[i]);
        else if(c == 'C')
            data->ceiling[i] = ft_atoi(splitted_colors[i]);
        i++;
    }
	if(splitted_colors[3])
	{
		data->floor[0] = -1;
		data->ceiling[0] = -1;
	}
    free_double(splitted_colors); 
}

char* store_map(char **map, char *aux, int fd)
{
    int i;

    i = 0;
    while (aux && aux[0] != '\n')
    {
        map[i] = ft_strtrim(aux, "\n");
        free(aux);
        aux = get_next_line(fd);
        i++;
    }
    return(aux);
}

void	read_map(t_data *data, int fd)
{
	char	*aux;

	aux = get_next_line(fd);
	aux = skip_empty(aux, fd);
	if (aux && (aux[0] == 'C' || aux[0] == 'F'))
		aux = store_textures(fd, data->colors, aux, 2);
	else
		aux = store_textures(fd, data->imgs, aux, 4);
	aux = skip_empty(aux, fd);
	if (aux && (aux[0] == 'C' || aux[0] == 'F') && !data->colors)
		aux = store_textures(fd, data->colors, aux, 2);
	else
		aux = store_textures(fd, data->imgs, aux, 4);
    aux = skip_empty(aux, fd);
    aux = store_map(data->map, aux, fd);
    if(aux)
        free(aux);
    store_colors(data->colors[0], data, data->colors[0]->type[0]);
    store_colors(data->colors[1], data, data->colors[1]->type[0]);
	get_next_line(-1);
}