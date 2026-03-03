/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:15:35 by aosset-o          #+#    #+#             */
/*   Updated: 2026/03/03 16:16:13 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_extract_line(char **buffer)
{
	int		i;
	char	*aux;
	char	*temp;

	i = 0;
	while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		i++;
	aux = ft_substr(*buffer, 0, i + ((*buffer)[i] == '\n'));
	if (!aux)
		return (free(*buffer), *buffer = NULL, NULL);
	temp = ft_strdup(*buffer + i + ((*buffer)[i] == '\n'));
	if (!temp)
		return (free(*buffer), free(aux), *buffer = NULL, NULL);
	free(*buffer);
	*buffer = temp;
	return (aux);
}

static int	ft_get_position(int fd, char **buffer)
{
	char	*line;
	int		read_bytes;

	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (-1);
	read_bytes = read(fd, line, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		line[read_bytes] = '\0';
		*buffer = ft_strjoin(*buffer, line);
		if (!*buffer)
			return (free(line), -1);
		if (ft_strchr(*buffer, '\n'))
			break ;
		read_bytes = read(fd, line, BUFFER_SIZE);
	}
	free(line);
	return (read_bytes);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_strdup("");
		if (!buffer)
			return (NULL);
	}
	read_bytes = ft_get_position(fd, &buffer);
	if (read_bytes < 0 || (!read_bytes && !*buffer))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (ft_extract_line(&buffer));
}