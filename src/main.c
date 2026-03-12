/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:59:04 by matoledo          #+#    #+#             */
/*   Updated: 2026/03/12 18:26:36 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	if(argc != 2)
		return(ft_putendl_fd("Error\nInvalid number of arguments.", 1), 1);
	int fd;
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
		return(ft_putendl_fd("Error\nMap file does not exist.",1), 1);
	if(check_extension(argv[1]) == 1)
		return(close(fd), ft_putendl_fd("Error\nInvalid map extenson.",1), 1);
	t_data *data;
	data = ft_calloc(2, sizeof(t_data));
	init_data(data, argv[1]);
	if(data->map_len > 6)
		read_map(data, fd);
	for(int i = 0; i < 4; i++)
	 	printf("the orientation is: %s, and the texture is: %s", data->imgs[i]->type, data->imgs[i]->path);
	for(int j = 0; j < 3; j++)
	  	printf("the floor color is: %i, and the ceiling color is: %i\n", data->floor[j], data->ceiling[j]);
	for (int k = 0; data->map[k]; k++)
		printf("%s\n", data->map[k]);
	free_data(data);
	close(fd);
	return(0);
}
