/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 09:25:10 by aosset-o          #+#    #+#             */
/*   Updated: 2026/04/29 16:09:53 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef struct s_textures
{
	char		*type;
	char		*path;
}				t_textures;

typedef struct s_data
{
	int			floor[3];
	int			ceiling[3];
	char		**map;
	t_textures	**imgs;
}				t_data;

typedef struct s_parse
{
	int			map_len;
	int			img_len;
	int			clr_len;
	t_textures	**colors;
}				t_parse;

void			init_structures(t_data *data, t_parse *parse, char *av1);
void			init_textures(t_textures **imgs, int len);
void			free_data(t_data *data);
void			free_parse(t_parse *parse);
void			free_img(t_textures **imgs);
void			ft_free(t_data *data, t_parse *parse, int fd);
void			read_map(t_data *data, t_parse *parse, int fd);
char			*skip_empty(char *aux, int fd);
char			*store_map(char **map, char *aux, int fd);
int				store_elements(int fd, t_data *data, t_parse *parse,
					char **aux);
void			colors_int(t_textures *colors, t_data *data, char c);
int				is_img(char *str);
int				is_color(char *str);
int				is_valid(char c);
int				check_extension(char *av1);
int				check_textures(t_data *data);
int				check_colors(t_data *data, t_parse *parse);
int				check_map(t_data *data, t_parse *parse);
int				check_zeros(char **map);
int				ft_parse(t_data *data, t_parse *parse, int fd);
int				ft_count_spaces(char *str, int flag);
#endif