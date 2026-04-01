/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 06:12:12 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/01 12:05:27 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	visual(int key_code, t_screen *screen)
{
	t_player	*p;

	p = player(NULL);
	(void)screen;
	if (key_code == 0xff51)
	{
		rotate_vector(&p->direction, -0.1);
		rotate_vector(&p->camera_plane, -0.1);
		printf("left\n");
	}
	if (key_code == 0xff53)
	{
		rotate_vector(&p->direction, 0.1);
		rotate_vector(&p->camera_plane, 0.1);
		printf("right\n");
	}
	//TODO: actualizar la dirección del jugador en el mapa
	draw_image(world_map(NULL));
	printf("direction = %f, %f\n", p->direction.x, p->direction.y);

}

void	movement(int key_code, t_screen *screen)
{
	t_player	*p;

	p = player(NULL);
	(void)screen;
	if (key_code == 0x77)
	{
		p->position.x += p->speed * p->direction.x;
		p->position.y += p->speed * p->direction.y;
		printf("w\n");
	}
	if (key_code == 0x73)
	{
		p->position.x -= p->speed * p->direction.x;
		p->position.y -= p->speed * p->direction.y;
		printf("s\n");
	}
	if (key_code == 0x61)
	{
		p->position.x -= p->speed * p->direction.y;
		p->position.y += p->speed * p->direction.x;
		printf("a\n");
	}
	if (key_code == 0x64)
	{
		p->position.x += p->speed * p->direction.y;
		p->position.y -= p->speed * p->direction.x;
		printf("d\n");
	}
	//TODO: actualizar en el mapa la posoción del jugador
	draw_image(world_map(NULL));
	printf("position = %f, %f\n", p->position.x, p->position.y);
}

int	key_hook(int key_code, t_screen *screen)
{
	// printf("key_code: %d\n", key_code);
	if (key_code == 0xff51 || key_code == 0xff53)
		visual(key_code, screen);
	if (key_code == 0x77 || key_code == 0x61
		|| key_code == 0x73 || key_code == 0x64)
		movement(key_code, screen);
	if (key_code == 0xff1b)
		close_window(screen);
	return (0);
}
