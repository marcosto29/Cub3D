/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:30:19 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/03 21:22:15 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "include/mlx/mlx.h"
# include "stdlib.h"
# include "stdio.h"
# include "math.h"
# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 800
# endif
# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 800
# endif

typedef struct screen
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_screen;

typedef struct vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct player
{
	t_vector	position;
	t_vector	direction;
	t_vector	camera_plane;
	double		speed;
}				t_player;

typedef struct image_data
{
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	char	*image;
}				t_image_data;

int			initialize_minilibx(void);
int			key_hook(int keyCode);
int			mouse_hook(int button, int x, int y);
int			close_window();
t_screen	*screen(void);
t_player	*player();
void		draw_image();
char		**world_map(char **world_map);
void		rotate_vector(t_vector *vector, double angle);
#endif