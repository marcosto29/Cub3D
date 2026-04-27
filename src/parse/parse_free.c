/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:33:20 by aosset-o          #+#    #+#             */
/*   Updated: 2026/04/27 19:17:07 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_img(t_textures **imgs)
{
	int	i;

	i = 0;
	while (imgs[i])
	{
		if (imgs[i]->type)
			free(imgs[i]->type);
		if (imgs[i]->path)
			free(imgs[i]->path);
		free(imgs[i]);
		i++;
	}
	free(imgs);
	imgs = NULL;
}

void free_parse(t_parse *parse)
{
	if(parse->colors)
		free_img(parse->colors);
	free(parse);
	parse = NULL;
}
void	free_data(t_data *data)
{
	if (data->imgs)
		free_img(data->imgs);
	if (data->map)
		ft_free_double(data->map);
	free(data);
	data = NULL;
}
