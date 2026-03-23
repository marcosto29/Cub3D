/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 06:12:12 by matoledo          #+#    #+#             */
/*   Updated: 2026/03/23 07:51:05 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	visual(int key_code, t_screen *screen)
{
	(void)screen;
	if (key_code == 0xff51)
		printf("left\n");
	if (key_code == 0xff52)
		printf("up\n");
	if (key_code == 0xff53)
		printf("right\n");
	if (key_code == 0xff54)
		printf("down\n");
}

void	movement(int key_code, t_screen *screen)
{
	(void)screen;
	if (key_code == 0x77)
		printf("w\n");
	if (key_code == 0x61)
		printf("a\n");
	if (key_code == 0x73)
		printf("s\n");
	if (key_code == 0x64)
		printf("d\n");
}

int	key_hook(int key_code, t_screen *screen)
{
	// printf("key_code: %d\n", key_code);
	if (key_code >= 0xff51 && key_code <= 0xff54)
		visual(key_code, screen);
	if (key_code == 0x77 || key_code == 0x61
		|| key_code == 0x73 || key_code == 0x64)
		movement(key_code, screen);
	if (key_code == 0xff1b)
		close_window(screen);
	return (0);
}
