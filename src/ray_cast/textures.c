/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 21:01:06 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/28 19:46:20 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture_data	create_texture_node(t_textures *img)
{
	t_texture_data	txt_data;

	txt_data.img_ptr = mlx_xpm_file_to_image(
			screen()->mlx,
			img->path,
			&txt_data.width,
			&txt_data.height);
	if (!txt_data.img_ptr)
	{
		printf("no se puede abrir el archivo: %s\n", img->path);
		return (txt_data);
	}
	txt_data.texture = mlx_get_data_addr(
			txt_data.img_ptr,
			&txt_data.img_data.bpp,
			&txt_data.img_data.ls,
			&txt_data.img_data.end);
	txt_data.side = ft_strdup(img->type);
	return (txt_data);
}

t_texture_data	*initialize_textures(t_textures **imgs)
{
	int				i;
	t_texture_data	*textures;

	textures = ft_calloc(5, sizeof(t_texture_data));
	if (!textures)
		return (NULL);
	i = 0;
	while (imgs[i])
	{
		textures[i] = create_texture_node(imgs[i]);
		if (!textures[i].img_ptr)
		{
			free_textures(textures);
			return (NULL);
		}
		i++;
	}
	textures[i].img_ptr = NULL;
	return (textures);
}

t_texture_data	*get_texture(t_textures **imgs)
{
	static t_texture_data	*textures_data = NULL;

	if (imgs && !textures_data)
	{
		textures_data = initialize_textures(imgs);
		if (!textures_data)
			return (NULL);
	}
	return (textures_data);
}

t_texture_data	texture_side(int side)
{
	t_texture_data	*texture;
	int				i;
	char			*cside;

	i = 0;
	texture = get_texture(NULL);
	if (side == 0)
		cside = "EA";
	if (side == 1)
		cside = "WE";
	if (side == 2)
		cside = "SO";
	if (side == 3)
		cside = "NO";
	while (ft_strncmp(texture[i].side, cside, 2) != 0)
		i++;
	return (texture[i]);
}
