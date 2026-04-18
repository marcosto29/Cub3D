/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:31:05 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/18 15:53:06 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Debuggeo
void	print_map(void)
{
	char	**w_map;
	int		i;

	w_map = world_info(NULL);
	i = 0;
	while (i < 24)
	{
		printf("%s\n", w_map[i]);
		i++;
	}
}

int	game_loop(void)
{
	static struct timeval	old_time = {0};
	struct timeval			current_time;
	double					frame_time;

	gettimeofday(&current_time, NULL);
	if (old_time.tv_sec == 0 && old_time.tv_usec == 0)
		old_time = current_time;
	frame_time = (current_time.tv_sec - old_time.tv_sec)
		+ (current_time.tv_usec - old_time.tv_usec) / 1000000.0;
	old_time = current_time;
	printf("FPS: %f\n", 1.0 / frame_time);
	movement(frame_time);
	visual(frame_time);
	print_map();
	draw_image();
	return (0);
}
