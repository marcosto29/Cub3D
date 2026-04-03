/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 06:12:12 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/03 22:53:36 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	look_direction(t_player *p)
{
	int	x;
	int	y;

	x = abs((int)(p->direction.x * 10));
	y = abs((int)(p->direction.y * 10));
	if (x > y)
	{
		if (p->direction.x < 0)
			return 'N';
		return 'S';
	}
	if (p->direction.y < 0)
		return 'W';
	return 'E';
}

void	visual(int key_code)
{
	t_player	*p;
	char		**w_map;

	w_map = world_map(NULL);
	p = player(NULL);
	if (key_code == 0xff53)
	{
		rotate_vector(&p->direction, -0.1);
		rotate_vector(&p->camera_plane, -0.1);
		printf("left\n");
	}
	if (key_code == 0xff51)
	{
		rotate_vector(&p->direction, 0.1);
		rotate_vector(&p->camera_plane, 0.1);
		printf("right\n");
	}
	w_map[(int)p->position.x][(int)p->position.y] = look_direction(p);
	draw_image(w_map);
	printf("direction = %f, %f\n", p->direction.x, p->direction.y);
	printf("direction = %c\n", w_map[(int)p->position.x][(int)p->position.y]);

}

t_vector	move(int key_code, t_player *p)
{
	t_vector	new_pos;

	new_pos = p->position;
	if (key_code == 0x77)
	{
		new_pos.x += p->speed * p->direction.x;
		new_pos.y += p->speed * p->direction.y;
	}
	if (key_code == 0x73)
	{
		new_pos.x -= p->speed * p->direction.x;
		new_pos.y -= p->speed * p->direction.y;
	}
	if (key_code == 0x61)
	{
		new_pos.x -= p->speed * p->direction.y;
		new_pos.y += p->speed * p->direction.x;
	}
	if (key_code == 0x64)
	{
		new_pos.x += p->speed * p->direction.y;
		new_pos.y -= p->speed * p->direction.x;
	}
	return (new_pos);
}

void	print_map()
{
	char	**w_map;
	int		i;

	w_map = world_map(NULL);
	i = 0;
	while (i < 24)
	{
		printf("%s\n", w_map[i]);
		i++;
	}
}

int	is_letter(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (0);
	return (1);
}

void	update_position(t_player *p, char **w_map, t_vector new_pos)
{
	char		aux;
	t_vector	previous_pos;

	if (w_map[(int)new_pos.x][(int)new_pos.y] != '0' &&
		is_letter(w_map[(int)new_pos.x][(int)new_pos.y]) == 1)
		return;
	previous_pos = p->position;
	p->position.x = new_pos.x;
	p->position.y = new_pos.y;
	if (((int)new_pos.x != (int)previous_pos.x || (int)new_pos.y != (int)previous_pos.y) &&
		w_map[(int)new_pos.x][(int)new_pos.y] == '0')
	{
		aux = w_map[(int)previous_pos.x][(int)previous_pos.y];
		w_map[(int)previous_pos.x][(int)previous_pos.y] = '0';
		w_map[(int)new_pos.x][(int)new_pos.y] = aux;
	}
	// print_map();
}

void	movement(int key_code)
{
	t_vector	new_pos;
	t_player	*p;
	char		**w_map;

	p = player(NULL);
	w_map = world_map(NULL);
	new_pos = move(key_code, p);
	update_position(p, w_map, new_pos);
	draw_image(w_map);
}

int	key_hook(int key_code)
{
	// printf("key_code: %d\n", key_code);
	if (key_code == 0xff51 || key_code == 0xff53)
		visual(key_code);
	if (key_code == 0x77 || key_code == 0x61
		|| key_code == 0x73 || key_code == 0x64)
		movement(key_code);
	if (key_code == 0xff1b)
		close_window(screen);
	return (0);
}
