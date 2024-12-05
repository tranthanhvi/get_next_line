/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:16:34 by thantran          #+#    #+#             */
/*   Updated: 2024/12/01 16:13:24 by thantran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;
	if ((!dst || !src) && size == 0)
		return (0);
	if (dst)
		dlen = ft_strlen(dst);
	else
		dlen = 0;
	slen = ft_strlen(src);
	if (size <= dlen)
		return (size + slen);
	i = 0;
	while (src[i] && (dlen + i < size - 1))
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);

}

int	find_newline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char *extract_line(char *buffer)
{
	char *line;
	int		newline_index;
	int		i;

	newline_index = find_newline(buffer);
	if (newline_index == -1)
		newline_index = strlen(buffer) - 1;
	line = malloc(newline_index + 2); //+1 for \n and +1 for \0
	if (!line)
		return (NULL);
	i = 0;
	while (i <= newline_index && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	
	return (line);
}

void	shift_buffer(char *buffer, int index)
{
	int	i;

	i = 0;

	if (index == -1)
	{
		buffer[0] = '\0';
		return ;
	}
	while (buffer[index + i + 1] != '\0')
	{
		buffer[i] = buffer[index + i + 1];
		i++;
	}
	buffer[i] = '\0';
}
