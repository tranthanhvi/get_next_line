/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:16:37 by thantran          #+#    #+#             */
/*   Updated: 2024/11/29 22:16:37 by thantran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
 // Read from file descriptor into a buffer
 // Save left over data for subsequent calls (using static variable)
 // Return a single line from the data
	static char	buffer[BUFFER_SIZE + 1];
	char	temp[BUFFER_SIZE + 1];
	int	bytes_read;
	char *line;
	int i;
	int j;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	while (find_newline(buffer) == -1)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);

		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0) //EOF
			break ;
		temp[bytes_read] = '\0';
		i = 0;
		while (buffer[i] != '\0')
			i++;
		j = 0;
		while (temp[j] != '\0')
			buffer[i++] = temp[j++];
		buffer[i] = '\0';
	}
	if (buffer[0] == '\0')
		return (NULL);
	line = extract_line(buffer);
	if (line == NULL)
	{
		printf("extract_line() returned NULL\n");
    	return (NULL); //remove
	}
	// printf("Line to be returned: %s\n", line); // remove
	shift_buffer(buffer, find_newline(buffer));
	return (line);
}

int	main()
{
	int	fd = open("test_file.txt", O_RDONLY);
	char	*line;

	if (fd < 0)
	{
		printf("Failed to open file.\n");
		return (1);
	}
	printf("File opened succesfully!\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("1st print: %s", line);
		line = get_next_line(fd);
		// printf("2nd print: %s", line);
		// line = get_next_line(fd);
		// printf("3rd print: %s", line);
		// line = get_next_line(fd);

		free(line);
	}
	close(fd);
	return (0);
}