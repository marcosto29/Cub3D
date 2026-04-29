/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:34:32 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/29 16:13:16 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_vector(t_dvector *vector, double angle)
{
	double	old_x;

	old_x = vector->x;
	vector->x = old_x * cos(angle) - vector->y * sin(angle);
	vector->y = old_x * sin(angle) + vector->y * cos(angle);
}

char	look_direction(t_player *p)
{
	int	x;
	int	y;

	x = abs((int)(p->direction.x * 10));
	y = abs((int)(p->direction.y * 10));
	if (x > y)
	{
		if (p->direction.x < 0)
			return ('N');
		return ('S');
	}
	if (p->direction.y < 0)
		return ('W');
	return ('E');
}

void	rotation(double frame_time)
{
	t_player	*p;
	char		**w_map;

	w_map = world_info(NULL);
	p = player();
	if (screen()->keys.left == 1)
	{
		rotate_vector(&p->direction, frame_time * p->speed);
		rotate_vector(&p->camera_plane, frame_time * p->speed);
	}
	if (screen()->keys.right == 1)
	{
		rotate_vector(&p->direction, -(frame_time * p->speed));
		rotate_vector(&p->camera_plane, -(frame_time * p->speed));
	}
	w_map[(int)p->position.x][(int)p->position.y] = look_direction(p);
	printf("direction = %f, %f\n", p->direction.x, p->direction.y);
	printf("direction = %c\n", w_map[(int)p->position.x][(int)p->position.y]);
}
