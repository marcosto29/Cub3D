/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 22:14:22 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/28 19:46:26 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pixel_color_img(int side, int i, t_ray_cast *ray_cast)
{
	t_texture_data	texture;
	double			offset;
	double			percentage;
	i_vector		tex;
	int				pos;

	texture = texture_side(side);
	offset = i - (SCREEN_HEIGHT / 2 - ray_cast->wall_height / 2);
	percentage = offset / ray_cast->wall_height;
	tex.y = (int)(percentage * texture.height);
	if (tex.y < 0)
		tex.y = 0;
	if (tex.y >= texture.height)
		tex.y = texture.height - 1;
	tex.x = (int)(ray_cast->x_coor * texture.width);
	if ((side == 2 || side == 3) && ray_cast->ray.x > 0)
		tex.x = texture.width - tex.x - 1;
	if ((side == 0 || side == 1) && ray_cast->ray.y < 0)
		tex.x = texture.width - tex.x - 1;
	pos = (tex.y * texture.img_data.ls)
		+ (tex.x * (texture.img_data.bpp / 8));
	return (*(unsigned int *)(texture.texture + pos));
}

int	color(int hitted, int side, int i, t_ray_cast *ray_cast)
{
	int	*cols;

	if (hitted == 2)
	{
		cols = get_colors(NULL)[0];
		return (((cols[0] & 0xff) << 16)
			+ ((cols[1] & 0xff) << 8)
			+ (cols[2] & 0xff));
	}
	if (hitted == 3)
	{
		cols = get_colors(NULL)[1];
		return (((cols[0] & 0xff) << 16)
			+ ((cols[1] & 0xff) << 8)
			+ (cols[2] & 0xff));
	}
	if (hitted == 1)
		return (pixel_color_img(side, i, ray_cast));
	return (0);
}

int	pixel_color(t_ray_cast *ray_cast, int i, int side, int wall)
{
	int				hitted;

	if (i >= ray_cast->pixel_bound.x && i <= ray_cast->pixel_bound.y)
		hitted = wall;
	else
	{
		if (i <= SCREEN_HEIGHT / 2)
			hitted = 2;
		else
			hitted = 3;
	}
	return (color(hitted, side, i, ray_cast));
}

int	paint_pixels(int pixel_column, t_ray_cast *ray_cast, int wall, int side)
{
	t_image_data	img_d;
	char			*img;
	int				i;
	int				pos;

	img = mlx_get_data_addr(screen()->img, &img_d.bpp,
			&img_d.ls, &img_d.end);
	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		pos = i * img_d.ls + pixel_column * (img_d.bpp / 8);
		*(unsigned int *)(img + pos)
			= mlx_get_color_value(screen()->mlx,
				pixel_color(ray_cast, i, side, wall));
		i++;
	}
	return (0);
}

void	draw_image(void)
{
	int			i;
	int			side;
	t_ray_cast	ray_cast;

	i = 0;
	if (screen()->img)
		mlx_destroy_image(screen()->mlx, screen()->img);
	screen()->img = mlx_new_image(screen()->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	while (i < SCREEN_WIDTH)
	{
		preparations(i, &ray_cast);
		initial_distance(&ray_cast);
		hit_loop(&ray_cast, &side);
		height_pixels(side, &ray_cast);
		paint_pixels(i, &ray_cast,
			world_info(NULL)[ray_cast.cum_pos.x][ray_cast.cum_pos.y] - '0',
			side);
		i++;
	}
	mlx_put_image_to_window(screen()->mlx, screen()->win, screen()->img, 0, 0);
}
