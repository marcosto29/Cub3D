/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 06:12:12 by matoledo          #+#    #+#             */
/*   Updated: 2026/04/06 12:36:39 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	key_pressed(int key_code)
{
	if (key_code == 0xff51)
		screen()->keys.left = 1;
	if (key_code == 0xff53)
		screen()->keys.right = 1;
	if (key_code == 0x77)
		screen()->keys.w = 1;
	if (key_code == 0x61)
		screen()->keys.a = 1;
	if (key_code == 0x73)
		screen()->keys.s = 1;
	if (key_code == 0x64)
		screen()->keys.d = 1;
	if (key_code == 0xff1b)
		close_window();
	return (1);
}

int	key_released(int key_code)
{
	if (key_code == 0xff51)
		screen()->keys.left = 0;
	if (key_code == 0xff53)
		screen()->keys.right = 0;
	if (key_code == 0x77)
		screen()->keys.w = 0;
	if (key_code == 0x61)
		screen()->keys.a = 0;
	if (key_code == 0x73)
		screen()->keys.s = 0;
	if (key_code == 0x64)
		screen()->keys.d = 0;
	return (1);
}
