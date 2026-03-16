/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 09:24:13 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/16 19:29:48 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_extension(char *av1)
{
    char **split;

    split = ft_split(av1, '.');
    if(ft_strncmp(split[1], "cub", 4) != 0)
    {
        free_double(split);
        return(1);
    }
    free_double(split);
    return(0);
}

char	*skip_empty(char *aux, int fd)
{
	while (aux && aux[0] == '\n')
	{
		free(aux);
		aux = get_next_line(fd);
	}
	return (aux);
}

int is_texture(char *str)
{
    static char *walls[4] = {
    "NO",
    "SO",
    "WE",
    "EA"
    };
    if(ft_strncmp(str, walls[0], 3 == 0))
        return(1);
    if(ft_strncmp(str, walls[1], 3 == 0))
        return(2);
    if(ft_strncmp(str, walls[2], 3 == 0))
        return(3);
    if(ft_strncmp(str, walls[3], 3 == 0))
        return(4);
    return(0);
}

int is_color(char *str)
{
    static char *colors[2] = {
    "F",
    "C",
    };
    if(ft_strncmp(str, colors[0], 2 == 0))
        return(1);
    if(ft_strncmp(str, colors[1], 2 == 0))
        return(2);
    return(0);
}
