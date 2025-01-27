/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:49:24 by thantran          #+#    #+#             */
/*   Updated: 2025/01/27 21:49:24 by thantran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*read_and_append(int fd, char *remaining)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(remaining, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		remaining = ft_strjoin(remaining, buff);
	}
	free(buff);
	return (remaining);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remaining;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	remaining = read_and_append(fd, remaining);
	if (!remaining)
		return (NULL);
	line = extract_line(remaining);
	remaining = save_remaining_buffer(remaining);
	return (line);
}
