/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:00:22 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/09 18:04:45 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
#include "libft/libft.h"
#include "mlx/mlx.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_textures
{
    char *type;
    char *path;
}t_textures;

typedef struct s_data
{
    t_textures **imgs;
    t_textures **colors;
}t_data;
void free_data(t_data *data);
void init_data(t_data *data);
void	free_double(char **pointer);
char *store_textures(int fd,  t_textures **textures, char *aux, int len);
void init_textures(t_textures **imgs, int len);
void free_img(t_textures **imgs);
void read_map(t_data *data, int fd);
#endif