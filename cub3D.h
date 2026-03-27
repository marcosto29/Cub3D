/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:30:19 by matoledo          #+#    #+#             */
/*   Updated: 2026/03/26 19:54:15 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "include/mlx/mlx.h"
# include "stdlib.h"
# include "stdio.h"
# include "math.h"
# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 400
# endif
# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 400
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
	t_vector	*position;
	t_vector	*direction;
	t_vector	*camera_plane;
}				t_player;

int			initialize_minilibx(void);
int			key_hook(int keyCode, t_screen *screen);
int			mouse_hook(int button, int x, int y, t_screen *param);
int			close_window(t_screen *screen);
void		free_player(t_player *camera);
t_screen	*screen(void);
t_player	*player(char **worldMap);
int			cub3D_loop(char **worldMap);
#endif