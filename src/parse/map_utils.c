/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:16:43 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/19 17:35:23 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int count_spaces(char *str)
{
	int i;
	i = 0;
	while (str[i] == ' ')
		i++;
	return(i);
}

int count_ones(char *str)
{
	int i;
	
	i = count_spaces(str);
	while (str[i] == '1')
		i++;
	return(i);
}