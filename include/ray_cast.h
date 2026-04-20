/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:30:19 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/20 10:28:48 by matoledo         ###   ########.fr       */
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
	//bits per pixel
	int		bpp;
	//line size
	int		ls;
	//endian
	int		end;
	//image
	char	*img;
}				t_image_data;

int			initialize_minilibx(void);
int			key_pressed(int key_code);
int			key_released(int key_code);
void		rotation(double frame_time);
void		movement(double frame_time);
int			game_loop(void);
int			mouse_hook(int button, int x, int y);
int			close_window(void);
t_screen	*screen(void);
t_player	*player(void);
void		draw_image(void);
char		**world_info(char **world_map);
void		rotate_vector(t_vector *vector, double angle);
void		print_map(void);
#endif