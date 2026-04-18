/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 06:55:38 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/06 12:11:51 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

int	close_window(void)
{
	if (screen()->img)
		mlx_destroy_image(screen()->mlx, screen()->img);
	if (screen()->win)
		mlx_destroy_window(screen()->mlx, screen()->win);
	mlx_destroy_display(screen()->mlx);
	free(screen()->mlx);
	free(screen());
	free(player());
	free_double(world_info(NULL));
	exit(0);
}
