/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:59:04 by matoledo          #+#    #+#             */
/*   Updated: 2026/03/23 18:59:14 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(t_data *data, int fd, int status)
{
	if (data)
		free_data(data);
	if (fd != 0)
		close(fd);
	exit(status);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_data	*data;

	if (argc != 2)
		return (ft_putendl_fd("Invalid number of arguments.", 1), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Map file does not exist.", 1), 1);
	if (check_extension(argv[1]) == 1)
		return (close(fd), ft_putendl_fd("Invalid map extenson.", 1), 1);
	data = ft_calloc(2, sizeof(t_data));
	init_data(data, argv[1]);
	if (data->map_len < 6)
		return (ft_exit(data, fd, 1), ft_putendl_fd("Invalid format", 1), 1);
	read_map(data, fd);
	if (check_textures(data) || check_colors(data) || check_map(data))
		ft_exit(data, fd, 1);
	return (ft_exit(data, fd, 0), 0);
}
