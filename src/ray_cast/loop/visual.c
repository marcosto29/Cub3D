/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:34:32 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/18 15:53:37 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	visual(double frame_time)
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
