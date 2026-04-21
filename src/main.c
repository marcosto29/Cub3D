/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:59:04 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/21 13:14:52 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(t_data *data, t_parse *parse, int fd)
{
	if (data)
		free_data(data);
	if(parse)
		free_parse(parse);
	if (fd != 0)
		close(fd);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_data	*data;
	t_parse *parse;

	if (argc != 2)
		return (ft_putendl_fd("Invalid number of arguments.", 1), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || check_extension(argv[1]) == 1)
		return (ft_putendl_fd("Invalid map.", 1), close(fd), 1);
	data = ft_calloc(2, sizeof(t_data));
	parse = ft_calloc(2, sizeof(t_parse));
	init_structures(data, parse, argv[1]);
	if (parse->map_len < 6 || parse->map_len > 256)
		return (ft_putendl_fd("Bad format.", 1), ft_free(data, parse, fd), 1);
	read_map(data, parse, fd);
	if (check_textures(data) || check_colors(data, parse) || check_map(data, parse))
		return(ft_free(data, parse, fd), 1);
	return(ft_free(data, parse, fd), 0);
}
