/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:31:50 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/06 10:18:26 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**world_info(char **w_map)
{
	static char		**world_map;

	if (!world_map)
		world_map = w_map;
	return world_map;
}