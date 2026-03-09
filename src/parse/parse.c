/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:23:05 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/09 18:58:00 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *store_textures(int fd,  t_textures **textures, char *aux, int len)
{
    char **splitted_args;
    int i;
    
    i = 0;
    while (i < len && aux && aux[0] != '\n')
    {
        splitted_args = ft_split(aux, ' ');
        if(!splitted_args || !splitted_args[0] || !splitted_args[1])
        {
            ft_putendl_fd("textures does not exit", 1);
            return (aux);
        }
        textures[i]->type = ft_strdup(splitted_args[0]);
        textures[i]->path = ft_strdup(splitted_args[1]);
        free(aux);
        free_double(splitted_args);
        aux = get_next_line(fd);
        i++;   
    }
    return (aux);
}
char *skip_empty(char *aux, int fd)
{
    while (aux && aux[0] == '\n')
    {
        free(aux);
        aux = get_next_line(fd);
    }
    return (aux);
}
void read_map(t_data *data, int fd)
{
    char *aux;
    
    aux = get_next_line(fd);
    aux = skip_empty(aux, fd);
    if(aux[0] == 'C' || aux[0] == 'F')
        aux = store_textures(fd, data->colors, aux, 2);
    else
        aux = store_textures(fd, data->imgs, aux, 4);
    aux = skip_empty(aux, fd);
    if(aux[0] == 'C' || aux[0] == 'F')
        aux = store_textures(fd, data->colors, aux, 2);
    else
        aux = store_textures(fd, data->imgs, aux, 4);
    if (aux)
        free(aux);
    get_next_line(-1);
}