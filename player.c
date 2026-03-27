/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 21:36:03 by matoledo          #+#    #+#             */
/*   Updated: 2026/03/26 19:56:08 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

size_t	ft_size(void *pointer, size_t data_type)
{
	size_t	size;

	size = 0;
	if (!pointer)
		return (size);
	while (*(char *)pointer)
	{
		size++;
		pointer++;
	}
	return (size / data_type);
}

t_vector	*initial_plane(t_vector *direction_ray, double ratio)
{
	t_vector	*camera_plane;

	camera_plane = malloc(sizeof(t_vector));
	if (!camera_plane)
		return(NULL);
	//el plano camara tien que ser un vector perpendicular al rayo de dirección
	//el método más rápido para sacar un vector perpendicular es intercambiar los valores y poner un valor en negativo
	//V = (2, 0) -> perpendicular -> V = (0, -2)
	//aparte, el ratio que tenga este plano con el rayo determinará el ángulo de visión (en shooters suele ser 66%)
	camera_plane->x = direction_ray->y * ratio;
	camera_plane->y = -direction_ray->x * ratio;
	return (camera_plane);
}

t_vector	*initial_direction(char direction_char)
{
	t_vector	*direction;

	direction = malloc(sizeof(t_vector));
	if (!direction)
		return (NULL);
	direction->x = 0;
	direction->y = 0;
	if (direction_char == 'N')
		direction->x = -1;
	if (direction_char == 'S')
		direction->x = 1;
	if (direction_char == 'E')
		direction->y = 1;
	if (direction_char == 'W')
		direction->y = -1;
	return (direction);
}

t_vector	*initial_position(char **worldMap)
{
	t_vector	*position;
	int			x;
	int			y;

	position = malloc(sizeof(t_vector));
	if (!position)
		return (NULL);
	while (worldMap[x])
	{
		y = 0;
		while (worldMap[y])
		{
			if (worldMap[x][y] == 'N' || worldMap[x][y] == 'S' ||
				worldMap[x][y] == 'E' || worldMap[x][y] == 'W')
			{
				position->x = x;
				position->y = y;
				return (position);
			}
			y++;
		}
		x++;
	}
	free(position);
	return (NULL);
}

t_player	*create_player(char **worldMap)
{
	t_player	*player;
	t_vector	*position;
	t_vector	*direction_ray;
	t_vector	*camera_plane;

	position = initial_position(worldMap);
	if (!position)
		return (NULL);
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
	direction_ray = initial_direction(worldMap[(int)position->x][(int)position->y]);
	if (!direction_ray)
	{
		free(position);
		return (NULL);
	}
	//Vector para indicar el tamaño del plano, cuanto más pequeño, mas lejos la camara
	//como el vector tiene que ser perpendicular a la dirección del rayo sabemos su dirección
	//el vector solo tiene la información de lo grande que es
	camera_plane = initial_plane(direction_ray, 0.66);
	if (!camera_plane)
	{
		free(position);
		free(direction_ray);
		return (NULL);
	}
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

t_player	*player(char **worldMap)
{
	static t_player	*player;

	if (!player)
	{
		if (!worldMap)
			return(NULL);
		player = create_player(worldMap);
		if (!player)
			return (NULL);
	}
	return (player);
}
