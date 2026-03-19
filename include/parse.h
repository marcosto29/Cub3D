/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 09:25:10 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/19 18:42:40 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef struct s_textures
{
    char *type;
    char *path;
}t_textures;

typedef struct s_data
{
    int floor[3];
    int ceiling[3];
    int map_len;
    char **map;
    t_textures **imgs;
    t_textures **colors;
}t_data;

void free_data(t_data *data);
void init_data(t_data *data, char *av1);
void	free_double(char **pointer);
char *store_textures(int fd,  t_textures **data, char *aux, int len);
void init_textures(t_textures **imgs, int len);
void free_img(t_textures **imgs);
void read_map(t_data *data, int fd);
int check_extension(char *av1);
char *skip_empty(char *aux, int fd);
void free_img(t_textures **imgs);
char* store_map(char **map, char *aux, int fd);
void store_colors(t_textures *colors, t_data *data, char c);
int	is_img(char *str);
int is_color(char *str);
int is_valid(char c);
int	check_textures(t_data *data);
int	check_colors(t_data *data);
int	check_map(t_data *data);
#endif