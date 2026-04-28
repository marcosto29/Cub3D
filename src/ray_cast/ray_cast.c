/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:32:01 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/28 17:15:09 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	preparations(int pixel, t_ray_cast *ray_cast)
{
	double		camera_x;

	camera_x = 2 * pixel / (double)SCREEN_WIDTH - 1;
	ray_cast->ray.x = player()->direction.x
		+ (player()->camera_plane.x * camera_x);
	ray_cast->ray.y = player()->direction.y
		+ (player()->camera_plane.y * camera_x);
	ray_cast->dist_ray_wall.x = fabs(1 / ray_cast->ray.x);
	ray_cast->dist_ray_wall.y = fabs(1 / ray_cast->ray.y);
	ray_cast->step_direction.x = 1;
	ray_cast->step_direction.y = 1;
}

void	initial_distance(t_ray_cast *ray_cast)
{
	ray_cast->cum_pos.x = (int)player()->position.x;
	ray_cast->cum_pos.y = (int)player()->position.y;
	if (ray_cast->ray.x < 0)
	{
		ray_cast->step_direction.x *= -1;
		ray_cast->cum_dist.x = (player()->position.x - ray_cast->cum_pos.x)
			* ray_cast->dist_ray_wall.x;
	}
	else
		ray_cast->cum_dist.x = (ray_cast->cum_pos.x + 1 - player()->position.x)
			* ray_cast->dist_ray_wall.x;
	if (ray_cast->ray.y < 0)
	{
		ray_cast->step_direction.y *= -1;
		ray_cast->cum_dist.y = (player()->position.y - ray_cast->cum_pos.y)
			* ray_cast->dist_ray_wall.y;
	}
	else
		ray_cast->cum_dist.y = (ray_cast->cum_pos.y + 1 - player()->position.y)
			* ray_cast->dist_ray_wall.y;
}

void	set_hit_side(int *side, i_vector cum_pos, int axis)
{
	if (axis == 0)
	{
		if (player()->position.y > cum_pos.y)
			*side = 0;
		else
			*side = 1;
	}
	else
	{
		if (player()->position.x > cum_pos.x)
			*side = 2;
		else
			*side = 3;
	}
}

void	hit_loop(t_ray_cast *ray_cast, int *side)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray_cast->cum_dist.y < ray_cast->cum_dist.x)
		{
			ray_cast->cum_dist.y += ray_cast->dist_ray_wall.y;
			ray_cast->cum_pos.y += ray_cast->step_direction.y;
			set_hit_side(side, ray_cast->cum_pos, 0);
		}
		else
		{
			ray_cast->cum_dist.x += ray_cast->dist_ray_wall.x;
			ray_cast->cum_pos.x += ray_cast->step_direction.x;
			set_hit_side(side, ray_cast->cum_pos, 1);
		}
		if (world_info(NULL)[ray_cast->cum_pos.x]
			[ray_cast->cum_pos.y] - '0' > 0)
			hit = 1;
	}
}

void	height_pixels(int side, t_ray_cast *ray_cast)
{
	double	wall_hitted_distance;

	if (side == 0 || side == 1)
		wall_hitted_distance = ray_cast->cum_dist.y - ray_cast->dist_ray_wall.y;
	else
		wall_hitted_distance = ray_cast->cum_dist.x - ray_cast->dist_ray_wall.x;
	if (wall_hitted_distance == 0)
		wall_hitted_distance = 0.000001;
	ray_cast->wall_height = WALL_HEIGHT / wall_hitted_distance;
	ray_cast->pixel_bound.x = SCREEN_HEIGHT / 2 - ray_cast->wall_height / 2;
	if (ray_cast->pixel_bound.x < 0)
		ray_cast->pixel_bound.x = 0;
	ray_cast->pixel_bound.y = SCREEN_HEIGHT / 2 + ray_cast->wall_height / 2;
	if (ray_cast->pixel_bound.y > SCREEN_HEIGHT - 1)
		ray_cast->pixel_bound.y = SCREEN_HEIGHT - 1;
	if (side == 0 || side == 1)
		ray_cast->x_coor = (double)player()->position.x + wall_hitted_distance
			* ray_cast->ray.x;
	else
		ray_cast->x_coor = (double)player()->position.y + wall_hitted_distance
			* ray_cast->ray.y;
	ray_cast->x_coor -= floor(ray_cast->x_coor);
}
