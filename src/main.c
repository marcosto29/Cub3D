/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:59:04 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/28 19:53:16 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_parse(t_data *data, t_parse *parse, int fd)
{
	if (data->imgs)
		free_img(data->imgs);
	if (parse)
		free_parse(parse);
	if (fd != 0)
		close(fd);
}

int	init_ray_cast(t_data *data, t_parse *parse, int fd)
{
	if (get_texture(data->imgs) == NULL)
	{
		free_mlx();
		ft_free_double(data->map);
		ft_free_parse(data, parse, fd);
		free(data);
		return (1);
	}
	prepare_colors(data->ceiling, data->floor);
	world_info(data->map);
	if (player() == NULL || initialize_minilibx(data) == 1)
		return (1);
	return (0);
}

void	ft_free(t_data *data, t_parse *parse, int fd)
{
	if (data)
		free_data(data);
	if (parse)
		free_parse(parse);
	if (fd != 0)
		close(fd);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_data	*data;
	t_parse	*parse;

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
		return (ft_free(data, parse, fd), 1);
	if (init_ray_cast(data, parse, fd) == 1)
		return (1);
	ft_free_parse(data, parse, fd);
	draw_image();
	mlx_loop(screen()->mlx);
	return (0);
}
