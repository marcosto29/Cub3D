/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 07:46:51 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/27 20:30:52 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_events(void	*window, t_data *data)
{
	mlx_mouse_hook(window, mouse_hook, screen());
	mlx_hook(window, 17, 1L << 1, close_window, data);
	mlx_hook(window, 2, 1L << 0, key_pressed, data);
	mlx_hook(window, 3, 1L << 1, key_released, screen());
	mlx_loop_hook(screen()->mlx, game_loop, NULL);
}

void	*create_window(void *mlx, t_data *data)
{
	void	*window;

	window = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!window)
		return (NULL);
	initialize_events(window, data);
	return (window);
}

t_screen	*create_screen(void)
{
	t_screen	*screen;

	screen = ft_calloc(1, sizeof(t_screen));
	if (!screen)
		return (NULL);
	screen->mlx = mlx_init();
	if (!screen->mlx)
	{
		free(screen);
		return (NULL);
	}
	return (screen);
}

t_screen	*screen(void)
{
	static t_screen	*screen;

	if (!screen)
	{
		screen = create_screen();
		if (!screen)
			return (NULL);
	}
	return (screen);
}

int	initialize_minilibx(t_data *data)
{
	if (!screen())
		return (1);
	screen()->win = create_window(screen()->mlx, data);
	if (!screen()->win)
	{
		free(screen()->mlx);
		free(screen());
		return (1);
	}
	return (0);
}
