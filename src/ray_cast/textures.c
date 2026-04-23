/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 21:01:06 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/23 20:43:07 by matoledo         ###   ########.fr       */
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
	txt_data.texture = mlx_get_data_addr(
			txt_data.img_ptr,
			&txt_data.img_data.bpp,
			&txt_data.img_data.ls,
			&txt_data.img_data.end);
	return (txt_data);
}

t_texture_data	*initialize_textures(t_textures **imgs)
{
	int				i;
	t_texture_data	*textures;

	textures = ft_calloc(4, sizeof(t_texture_data));
	if (!textures)
		return (NULL);
	i = 0;
	while (imgs[i])
	{
		textures[i] = create_texture_node(imgs[i]);
		i++;
	}
	return (textures);
}

t_texture_data	*get_texture(t_textures **imgs)
{
	static t_texture_data	*textures_data = NULL;

	if (imgs && !textures_data)
		textures_data = initialize_textures(imgs);
	return (textures_data);
}
