/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 21:36:03 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/29 16:13:16 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_dvector	initial_plane(t_dvector direction_ray, double ratio)
{
	t_dvector	camera_plane;

	camera_plane.x = direction_ray.y * ratio;
	camera_plane.y = -direction_ray.x * ratio;
	return (camera_plane);
}

t_dvector	initial_direction(char direction_char)
{
	t_dvector	direction;

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

t_dvector	initial_position(char **worldMap)
{
	t_dvector	position;
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
	t_dvector	position;
	t_dvector	direction_ray;
	t_dvector	camera_plane;

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
