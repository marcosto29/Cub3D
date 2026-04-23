/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 21:36:03 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/21 17:32:51 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

d_vector	initial_plane(d_vector direction_ray, double ratio)
{
	d_vector	camera_plane;

	camera_plane.x = direction_ray.y * ratio;
	camera_plane.y = -direction_ray.x * ratio;
	return (camera_plane);
}

d_vector	initial_direction(char direction_char)
{
	d_vector	direction;

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

d_vector	initial_position(char **worldMap)
{
	d_vector	position;
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
	d_vector	position;
	d_vector	direction_ray;
	d_vector	camera_plane;

	position = initial_position(map);
	direction_ray = initial_direction(map[(int)position.x][(int)position.y]);
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
