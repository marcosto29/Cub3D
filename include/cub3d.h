/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:00:22 by aosset-o          #+#    #+#             */
/*   Updated: 2026/04/27 20:31:05 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "ray_cast.h"
# include "parse.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

t_texture_data	*get_texture(t_textures **imgs);
int				initialize_minilibx(t_data *data);
int				close_window(t_data *data);
int				key_pressed(int key_code, t_data *data);

#endif