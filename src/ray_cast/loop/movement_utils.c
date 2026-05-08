/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:24:01 by aosset-o          #+#    #+#             */
/*   Updated: 2026/05/08 14:25:14 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	can_move(char **map, double x, double y, double r)
{
	return (is_walkable(map, x - r, y - r) && is_walkable(map, x + r, y - r)
		&& is_walkable(map, x - r, y + r) && is_walkable(map, x + r, y + r)
		&& is_walkable(map, x, y - r) && is_walkable(map, x, y + r)
		&& is_walkable(map, x + r, y) && is_walkable(map, x - r, y));
}
