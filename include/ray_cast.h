/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:30:19 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/28 17:12:22 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CAST_H
# define RAY_CAST_H
# include <math.h>
# include <sys/time.h>
# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 800
# endif
# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 800
# endif
# ifndef WALL_HEIGHT
#  define WALL_HEIGHT SCREEN_HEIGHT / 2
# endif

typedef struct key_state
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	right;
	int	left;
}				t_key_state;

typedef struct screen
{
	void		*mlx;
	void		*win;
	void		*img;
	t_key_state	keys;
}				t_screen;

typedef struct double_vector
{
	double	x;
	double	y;
}				d_vector;

typedef struct integer_vector
{
	int	x;
	int	y;
}				i_vector;

typedef struct player
{
	d_vector	position;
	d_vector	direction;
	d_vector	camera_plane;
	double		speed;
}				t_player;

typedef struct image_data
{
	//bits per pixel
	int		bpp;
	//line size
	int		ls;
	//endian
	int		end;
}				t_image_data;

typedef struct texture_data
{
	char			*texture;
	void			*img_ptr;

	int				width;
	int				height;

	char			*side;
	t_image_data	img_data;
}				t_texture_data;


typedef struct ray_cast
{
	d_vector	ray;
	d_vector	dist_ray_wall;
	d_vector	cum_dist;
	i_vector	pixel_bound;
	double		x_coor;
	double		wall_height;
	i_vector	step_direction;
	i_vector	cum_pos;
}				t_ray_cast;

int				key_released(int key_code);
void			rotation(double frame_time);
void			movement(double frame_time);
int				game_loop(void);
int				mouse_hook(int button, int x, int y);
t_screen		*screen(void);
t_player		*player(void);
void			draw_image(void);
char			**world_info(char **world_map);
void			rotate_vector(d_vector *vector, double angle);
void			print_map(void);
void			preparations(int pixel, t_ray_cast *ray_cast);
void			initial_distance(t_ray_cast *ray_cast);
void			set_hit_side(int *side, i_vector cum_pos, int axis);
void			hit_loop(t_ray_cast *ray_cast, int *side);
void			height_pixels(int side, t_ray_cast *ray_cast);
void			free_textures(t_texture_data *textures);
void			prepare_colors(int *top, int *bottom);
int				**get_colors(int **colors);
void			free_mlx(void);


#endif