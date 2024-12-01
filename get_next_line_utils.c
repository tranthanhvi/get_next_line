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

int	find_newline(char *buffer) // return the index of the line
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
	extracted_line = malloc(newline_index + 2) //+1 for \n and +1 for \0
	if (!extracted_line)
		return (NULL);
	i = 0;
	while (i < newline_index)
	{
		extracted_line[j] = buffer[j];
		j++;
	}
	line[i + 1] = '\0';
	return (extract_line);
}