/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 09:24:13 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/10 09:39:16 by aosset-o         ###   ########.fr       */
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