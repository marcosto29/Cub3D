/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:23:05 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/04 19:02:24 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_textures(int fd,  t_textures **textures)
{
    char **splitted_args;
    char *aux;
    int i;
    
    i = 0;
    while (i < 4)
    {
        aux = get_next_line(fd);
        if(!aux)
            return(ft_putendl_fd("textures dooes not exit", 1), 1);
        splitted_args = ft_split(aux, ' ');
        if(!splitted_args)
        {
            ft_putendl_fd("textures dooes not exit", 1);
            return(free(aux), 1);
        }
        textures[i]->type = ft_strdup(splitted_args[0]);
        textures[i]->path = ft_strdup(splitted_args[1]);
        free(aux);
        free_double(splitted_args);
        i++;   
    }
    get_next_line(-1); 
    return(0);
}
