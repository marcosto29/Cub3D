/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:59:04 by matoledo          #+#    #+#             */
/*   Updated: 2026/03/02 19:52:24 by aosset-o         ###   ########.fr       */
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
	return(0);
}