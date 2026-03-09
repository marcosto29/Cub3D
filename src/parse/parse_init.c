/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:02:10 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/09 18:26:05 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_textures(t_textures **imgs, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		imgs[i] = ft_calloc(sizeof(t_textures), 1);
		i++;
	}
	imgs[len] = NULL;
	i = 0;
}

void init_data(t_data *data)
{
	data->imgs = ft_calloc(5, sizeof(t_textures *));
	init_textures(data->imgs, 4);
	data->colors = ft_calloc(3, sizeof(t_textures *));
	init_textures(data->colors, 2);
}