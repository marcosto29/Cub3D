/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:32:53 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/18 15:53:37 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_letter(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (0);
	return (1);
}

t_vector	move(t_player *p, double frame_time)
{
	t_vector	new_pos;

	new_pos = p->position;
	if (screen()->keys.w == 1)
	{
		new_pos.x += frame_time * p->speed * p->direction.x;
		new_pos.y += frame_time * p->speed * p->direction.y;
	}
	if (screen()->keys.s == 1)
	{
		new_pos.x -= frame_time * p->speed * p->direction.x;
		new_pos.y -= frame_time * p->speed * p->direction.y;
	}
	if (screen()->keys.a == 1)
	{
		new_pos.x -= frame_time * p->speed * p->direction.y;
		new_pos.y += frame_time * p->speed * p->direction.x;
	}
	if (screen()->keys.d == 1)
	{
		new_pos.x += frame_time * p->speed * p->direction.y;
		new_pos.y -= frame_time * p->speed * p->direction.x;
	}
	return (new_pos);
}

void update_position(t_player *p, char **w_map, t_vector new_pos)
{
    static char previous_char = '0';
    char        aux;
    t_vector    previous_pos;

    previous_pos = p->position;
    if (w_map[(int)new_pos.x][(int)previous_pos.y] == '0' ||
        is_letter(w_map[(int)new_pos.x][(int)previous_pos.y]) == 0)
        p->position.x = new_pos.x;
    if (w_map[(int)previous_pos.x][(int)new_pos.y] == '0' ||
        is_letter(w_map[(int)previous_pos.x][(int)new_pos.y]) == 0)
        p->position.y = new_pos.y;
    aux = w_map[(int)previous_pos.x][(int)previous_pos.y];
    w_map[(int)previous_pos.x][(int)previous_pos.y] = previous_char;
    previous_char = w_map[(int)p->position.x][(int)p->position.y];
    w_map[(int)p->position.x][(int)p->position.y] = aux;
}

void	movement(double frame_time)
{
	t_vector	new_pos;
	t_player	*p;
	char		**w_map;

	p = player();
	w_map = world_info(NULL);
	new_pos = move(p, frame_time);
	update_position(p, w_map, new_pos);
}
