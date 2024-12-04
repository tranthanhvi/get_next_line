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
	while (i < newline_index && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	
	return (line);
	 printf("Extracted line: %s\n", line); // Debug print
}

void	shift_buffer(char *buffer, int index)
{
	int	i;

	i = 0;
	while (buffer[index + 1] != '\0')
	{
		buffer[i] = buffer[index + i + 1];
		i++;
	}
	buffer[i] = '\0';
}
