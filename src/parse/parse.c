/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:02:10 by aosset-o          #+#    #+#             */
/*   Updated: 2026/04/29 16:39:22 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_imgs(char *aux, int fd)
{
	while (aux && aux[0] != '\n')
	{
		free(aux);
		aux = get_next_line(fd);
	}
	return (aux);
}

int	map_size(int fd)
{
	int		map_len;
	char	*aux;

	map_len = 0;
	aux = get_next_line(fd);
	aux = skip_empty(aux, fd);
	while (aux && aux[ft_count_spaces(aux, 0)] != '1')
	{
		free(aux);
		aux = get_next_line(fd);
	}
	while (aux && aux[0] != '\n')
	{
		map_len++;
		free(aux);
		aux = get_next_line(fd);
	}
	if (aux)
	{
		free(aux);
		map_len = 0;
	}
	return (get_next_line(-1), map_len);
}

void	init_textures(t_textures **imgs, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		imgs[i] = ft_calloc(sizeof(t_textures), 1);
		i++;
	}
	imgs[len] = NULL;
	i = 0;
}

void	init_structures(t_data *data, t_parse *parse, char *av1)
{
	int	fd2;

	fd2 = open(av1, O_RDONLY);
	parse->map_len = map_size(fd2);
	parse->img_len = 4;
	parse->clr_len = 2;
	close(fd2);
	if (parse->map_len >= 3 && parse->map_len <= 128)
		data->map = ft_calloc(parse->map_len + 1, sizeof(char *));
	data->imgs = ft_calloc(parse->img_len + 1, sizeof(t_textures *));
	init_textures(data->imgs, parse->img_len);
	parse->colors = ft_calloc(parse->clr_len + 1, sizeof(t_textures *));
	init_textures(parse->colors, parse->clr_len);
}

int	ft_parse(t_data *data, t_parse *parse, int fd)
{
	if (parse->map_len < 3 || parse->map_len > 128)
		return (ft_putendl_fd("Bad format.", 1), 1);
	read_map(data, parse, fd);
	if (check_textures(data))
		return (1);
	if (check_colors(data, parse))
		return (1);
	if (check_map(data, parse))
		return (1);
	return (0);
}
