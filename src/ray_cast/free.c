/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 06:55:38 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/23 13:15:21 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_texture_data *textures)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(screen()->mlx, textures[i].img_ptr);
		i++;
	}
	free(textures);
}

int	close_window(void)
{
	free_textures(get_texture(NULL));
	if (screen()->img)
		mlx_destroy_image(screen()->mlx, screen()->img);
	if (screen()->win)
		mlx_destroy_window(screen()->mlx, screen()->win);
	mlx_destroy_display(screen()->mlx);
	free(screen()->mlx);
	free(screen());
	free(player());
	ft_free_double(world_info(NULL));
	exit(0);
}
