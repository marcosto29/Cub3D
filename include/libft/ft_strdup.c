/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:54:10 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/04 18:34:32 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	allocate_memory;
	char	*pt_return;

	allocate_memory = ft_strlen(s);
	pt_return = ft_calloc(sizeof(char), allocate_memory + 1);
	if (!pt_return)
		return (NULL);
	ft_memcpy(pt_return, s, allocate_memory);
	return (pt_return);
}
