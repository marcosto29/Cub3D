/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:02:10 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/11 19:47:51 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *skip_imgs(char *aux, int fd)
{
    while (aux && aux[0] != '\n')
    {
        free(aux);
        aux = get_next_line(fd);
    }
    return (aux);
}
int map_size(int fd)
{
	int map_len;
	char *aux;
		
	map_len = 0;
	aux = get_next_line(fd);
	aux = skip_empty(aux, fd);
	aux = skip_imgs(aux, fd);
	aux = skip_empty(aux, fd);
	aux = skip_imgs(aux, fd);
	aux = skip_empty(aux, fd);
	while (aux && aux[0] != '\n')
	{
		free(aux);
		aux = get_next_line(fd);
		map_len++;
	}
	if(aux)
		free(aux);
	get_next_line(-1);
	return(map_len);
}
void init_textures(t_textures **imgs, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		imgs[i] = ft_calloc(sizeof(t_textures), 1);
		i++;
	}
	imgs[len] = NULL;
	i = 0;
}

void init_data(t_data *data, char *av1)
{
	int fd2;
	
	fd2 = open(av1, O_RDONLY);
	data->map_len = map_size(fd2);
	close(fd2);
	if(data->map_len > 6)
	{
		data->map = ft_calloc(data->map_len + 1, sizeof(char *));
		data->imgs = ft_calloc(5, sizeof(t_textures *));
		init_textures(data->imgs, 4);
	}
}