/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:13:41 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/18 16:13:58 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_double(char **pointer)
{
	char	**aux;

	if (!pointer || !*pointer)
		return ;
	aux = pointer;
	while (*aux)
	{
		free(*aux);
		aux++;
	}
	free(pointer);
	pointer = NULL;
}