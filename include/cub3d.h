/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:00:22 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/04 17:56:31 by aosset-o         ###   ########.fr       */
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
void	free_double(char **pointer);
int check_textures(int fd,  t_textures **textures);
void init_textures(t_textures **imgs);
void free_img(t_textures **imgs);
#endif