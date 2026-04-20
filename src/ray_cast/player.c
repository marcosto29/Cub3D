/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 21:36:03 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/20 10:26:30 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	initial_plane(t_vector direction_ray, double ratio)
{
	t_vector	camera_plane;

	//el plano camara tien que ser un vector perpendicular al rayo de dirección
	//el método más rápido para sacar un vector perpendicular es intercambiar los valores y poner un valor en negativo
	//V = (2, 0) -> perpendicular -> V = (0, -2)
	//aparte, el ratio que tenga este plano con el rayo determinará el ángulo de visión (en shooters suele ser 66%)
	camera_plane.x = direction_ray.y * ratio;
	camera_plane.y = -direction_ray.x * ratio;
	return (camera_plane);
}

t_vector	initial_direction(char direction_char)
{
	t_vector	direction;

	direction.x = 0;
	direction.y = 0;
	if (direction_char == 'N')
		direction.x = -1;
	if (direction_char == 'S')
		direction.x = 1;
	if (direction_char == 'E')
		direction.y = 1;
	if (direction_char == 'W')
		direction.y = -1;
	return (direction);
}

t_vector	initial_position(char **worldMap)
{
	t_vector	position;
	int			x;
	int			y;

	x = 0;
	position.x = 0;
	position.y = 0;
	while (worldMap[x])
	{
		y = 0;
		while (worldMap[x][y])
		{
			if (worldMap[x][y] == 'N' || worldMap[x][y] == 'S' ||
				worldMap[x][y] == 'E' || worldMap[x][y] == 'W')
			{
				position.x = x;
				position.y = y;
				return (position);
			}
			y++;
		}
		x++;
	}
	return (position);
}

t_player	*create_player(char **map)
{
	t_player	*player;
	t_vector	position;
	t_vector	direction_ray;
	t_vector	camera_plane;

	position = initial_position(map);
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
	direction_ray = initial_direction(map[(int)position.x][(int)position.y]);
	//Vector para indicar el tamaño del plano, cuanto más pequeño, mas lejos la camara
	//como el vector tiene que ser perpendicular a la dirección del rayo sabemos su dirección
	//el vector solo tiene la información de lo grande que es
	camera_plane = initial_plane(direction_ray, 0.66);
	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->position = position;
	player->direction = direction_ray;
	player->camera_plane = camera_plane;
	player->speed = 5;
	return (player);
}

t_player	*player(void)
{
	static t_player	*player;

	if (!player)
	{
		if (!world_info(NULL))
			return (NULL);
		player = create_player(world_info(NULL));
		if (!player)
			return (NULL);
	}
	return (player);
}
