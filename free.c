/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 06:55:38 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/03 21:39:24 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_window()
{
	if (screen()->img)
		mlx_destroy_image(screen()->mlx, screen()->img);
	if (screen()->win)
		mlx_destroy_window(screen()->mlx, screen()->win);
	mlx_destroy_display(screen()->mlx);
	free(screen()->mlx);
	free(screen());
	free(player(NULL));
	free(world_map(NULL));
	exit(0);
}
