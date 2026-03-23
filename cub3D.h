/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:30:19 by matoledo          #+#    #+#             */
/*   Updated: 2026/03/23 07:51:05 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/mlx/mlx.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct screen
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_screen;

int			initialize_minilibx(void);
t_screen	*screen(void);
int			key_hook(int keyCode, t_screen *screen);
int			mouse_hook(int button, int x, int y, t_screen *param);
int			close_window(t_screen *screen);