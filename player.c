/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 21:36:03 by matoledo          #+#    #+#             */
/*   Updated: 2026/03/24 12:01:15 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_player	*create_player(void)
{
	t_player	*player;
	t_vector	*position;
	t_vector	*direction_ray;
	t_vector	*camera_plane;

	position = malloc(sizeof(t_vector));
	if (!position)
		return (NULL);
	position->x = 20;
	position->y = 10;
	//con una dirección x = -1 y = 0 el jugador mira a la izquierda
	//si fuera x = 0 y = 1 miraría hacia alante
	//En función de X o Y mirará en una dirección u otra
	// 			   1
	// 			   |
	// 			   |
	//  -1 ________|________ 1
    //             |
	// 		       |
	// 		       |
	// 			  -1
	direction_ray = malloc(sizeof(t_vector));
	if (!direction_ray)
	{
		free(position);
		return (NULL);
	}
	direction_ray->x = -1;
	direction_ray->y = 0;
	//Vector para indicar el tamaño del plano, cuanto más pequeño, mas lejos la camara
	//como el vector tiene que ser perpendicular a la dirección del rayo sabemos su dirección
	//el vector solo tiene la información de lo grande que es
	camera_plane = malloc(sizeof(t_vector));
	if (!camera_plane)
	{
		free(position);
		free(direction_ray);
		return (NULL);
	}
	camera_plane->x = 0;
	camera_plane->y = 0.66;
	player = malloc(sizeof(t_player));
	if (!player)
	{
		free(position);
		free(direction_ray);
		free(camera_plane);
		return (NULL);
	}
	player->position = position;
	player->direction = direction_ray;
	player->camera_plane = camera_plane;
	return (player);
}

t_player	*player(void)
{
	static t_player	*camera;

	if (!camera)
	{
		camera = create_player();
		if (!camera)
			return (NULL);
	}
	return (camera);
}
