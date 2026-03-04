/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:33:20 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/04 18:12:09 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void init_textures(t_textures **imgs)
{
	int i;
	
	i = 0;
	while (i < 4)
	{
		imgs[i] = ft_calloc(sizeof(t_textures), 1);
		i++;
	}
	imgs[4] = NULL;
	i = 0;
}
void	free_double(char **pointer)
{
	char	**aux;

	if (!pointer || !*pointer)
		return ;
	aux = pointer;
	while (*aux)
	{
		free(*aux);
		aux++;
	}
	free(pointer);
	pointer = NULL;
}
void free_img(t_textures **imgs)
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