/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:45:22 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/16 19:48:30 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_textures(t_data *data)
{
	int i;
	int fd;
	
	i = 0;
	while (data->imgs[i])
	{
		fd = open(data->imgs[i]->path, O_RDONLY);
		if(fd == -1)
			return(ft_putendl_fd("Error\n can not texture.", 1), 1);
	}
	
}