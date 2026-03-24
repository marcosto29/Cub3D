/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 06:55:38 by matoledo          #+#    #+#             */
/*   Updated: 2026/03/24 11:26:57 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_window(t_screen *screen)
{
	if (screen->img)
		mlx_destroy_image(screen->mlx, screen->img);
	if (screen->win)
		mlx_destroy_window(screen->mlx, screen->win);
	mlx_destroy_display(screen->mlx);
	free(screen->mlx);
	free(screen);
	exit(0);
}

void	free_player(t_player *camera)
{
	free(camera->position);
	free(camera->direction);
	free(camera->camera_plane);
	free(camera);
}