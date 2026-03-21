/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:59:04 by matoledo          #+#    #+#             */
/*   Updated: 2026/03/21 17:35:16 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/mlx/mlx.h"
#include "cub3d.h"

void *close_window(t_screen *screen)
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

int	key_hook(int keyCode, t_screen *screen)
{
	//Movement
	// 65361 left arrow = 0xff51
	// 65363 right arrow = 0xff53
	// 65362 up arrow = 0xff52
	// 65364 down arrow = 0xff54
	//Visual
	// 119 w = 0x77
	// 97 a = 0x61
	// 115 s = 0x73
	// 100 d = 0x64
	//esc 65307 = 0xff1B
	if (keyCode == 0xff1b)
		close_window(screen);
	return (0);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	int	x_size = 400;
	int	y_size = 400;

	t_screen	*screen;
	screen = malloc(sizeof(t_screen));
	if (!screen)
		return (1);
	screen->mlx = mlx_init();
	if (!screen->mlx)
	{
		free(screen);
		return (1);
	}
	screen->win = mlx_new_window(screen->mlx, x_size, y_size, "cub3D");
	if (!screen->win)
	{
		free(screen->mlx);
		free(screen);
		return (1);
	}
	screen->img = mlx_new_image(screen->mlx, x_size, y_size);
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img, 0, 0);
	mlx_key_hook(screen->win, key_hook, screen);
	mlx_loop(screen->mlx);
}