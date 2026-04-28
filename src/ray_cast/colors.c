/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:45:03 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/28 19:47:39 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	**get_colors(int **colors)
{
	static int	**cols = NULL;

	if (!cols && colors)
		cols = colors;
	return (cols);
}

void	prepare_colors(int *top, int *bottom)
{
	int	**colors;

	colors = ft_calloc(2, sizeof(int *));
	colors[0] = top;
	colors[1] = bottom;
	get_colors(colors);
}
