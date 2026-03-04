/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:59:04 by matoledo          #+#    #+#             */
/*   Updated: 2026/03/04 18:06:03 by aosset-o         ###   ########.fr       */
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
	t_textures **imgs;
	imgs = ft_calloc(5, sizeof(t_textures *));
	init_textures(imgs);
	if(check_textures(fd, imgs) == 1)
		return(close(fd), 1);
	for(int i = 0; i < 4; i++)
		printf("the orientation is: %s, and the texture is: %s", imgs[i]->type, imgs[i]->path);
	close(fd);
	free_img(imgs);
	return(0);
}