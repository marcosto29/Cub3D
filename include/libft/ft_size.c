/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 10:24:58 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/20 10:25:43 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_size(void *pointer, size_t data_type)
{
	size_t	size;

	size = 0;
	if (!pointer)
		return (size);
	while (*(char *)pointer)
	{
		size++;
		pointer++;
	}
	return (size / data_type);
}