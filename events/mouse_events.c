/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 06:29:20 by matoledo          #+#    #+#             */
/*   Updated: 2026/03/23 07:51:43 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	mouse_hook(int button, int x, int y, t_screen *screen)
{
	(void)screen;
	// printf("key_code: %d", key_code);
	if (button == 1)
		printf("left clcik\n");
	if (button == 2)
		printf("scroll clcik\n");
	if (button == 3)
		printf("right clcik\n");
	if (button == 4)
		printf("scroll up\n");
	if (button == 5)
		printf("scroll down\n");
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	return (0);
}
