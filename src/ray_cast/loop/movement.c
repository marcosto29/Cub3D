/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:32:53 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/29 16:13:16 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_dvector	move(t_player *p, double frame_time)
{
	t_dvector	new_pos;

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

int	get_map_height(char **map)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	update_position(t_player *p, char **w_map, t_dvector new_pos)
{
	static char	previous_char = '0';
	char		aux;
	t_dvector	previous_pos;

	previous_pos = p->position;
	if ((int)new_pos.x < 0
		|| (int)new_pos.x >= get_map_height(w_map))
		return ;
	if ((int)new_pos.y < 0
		|| (int)new_pos.y >= (int)ft_strlen(w_map[(int)new_pos.x]))
		return ;
	if (w_map[(int)new_pos.x][(int)previous_pos.y] == '0' ||
		ft_isalpha(w_map[(int)new_pos.x][(int)previous_pos.y]) == 1)
		p->position.x = new_pos.x;
	if (w_map[(int)previous_pos.x][(int)new_pos.y] == '0' ||
		ft_isalpha(w_map[(int)previous_pos.x][(int)new_pos.y]) == 1)
		p->position.y = new_pos.y;
	aux = w_map[(int)previous_pos.x][(int)previous_pos.y];
	w_map[(int)previous_pos.x][(int)previous_pos.y] = previous_char;
	previous_char = w_map[(int)p->position.x][(int)p->position.y];
	w_map[(int)p->position.x][(int)p->position.y] = aux;
}

void	movement(double frame_time)
{
	t_dvector	new_pos;
	t_player	*p;
	char		**w_map;

	p = player();
	w_map = world_info(NULL);
	new_pos = move(p, frame_time);
	update_position(p, w_map, new_pos);
}
