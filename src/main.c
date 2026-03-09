/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:59:04 by matoledo          #+#    #+#             */
/*   Updated: 2026/03/09 18:05:12 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	if(argc != 2)
		return(ft_putendl_fd("The number of arguments is invalid", 1), 1);
	int fd;
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
		return(ft_putendl_fd("Map does not exist",1), 1);
	t_data *data;
	data = ft_calloc(2, sizeof(t_data));
	init_data(data);
	read_map(data, fd);
	for(int i = 0; i < 4; i++)
	 	printf("the orientation is: %s, and the texture is: %s", data->imgs[i]->type, data->imgs[i]->path);
	for(int i = 0; i < 2; i++)
	 	printf("the orientation is: %s, and the texture is: %s", data->colors[i]->type, data->colors[i]->path);
	free_data(data);
	close(fd);
	return(0);
}