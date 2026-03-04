/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:23:05 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/03 17:53:38 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int count_map_lines(int start, int fd)
{
    
}
int store_textures(int fd,  t_textures **textures)
{
    char **splitted_args;
    char *aux;
    int i;
    
    i = 0;
    while (!get_next_line(fd))
        ;
    while (i < 4)
    {
        aux = get_next_line(fd);
        if(!aux)
            return(1);
        splitted_args = ft_split(aux, ' ');
        if(!splitted_args)
            return(free(aux), 1);
        textures[i]->type = splitted_args[0];
        textures[i]->path = splitted_args[1];
        free(aux);
        free_double(splitted_args);
        i++;   
    } 
    return(0);
}
int check_map(int fd)
{
    
}
