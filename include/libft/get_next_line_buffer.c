/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:42:01 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/23 19:08:19 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_buffer(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	else
		buffer = NULL;
}
