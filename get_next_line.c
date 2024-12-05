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
	static char	buffer[BUFFER_SIZE + 1];
	char		temp[BUFFER_SIZE + 1];
	int			bytes_read;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (find_newline(buffer) == -1)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			break ;
		temp[bytes_read] = '\0';
		// i = 0;
		// while (buffer[i] != '\0')
		// 	i++;
		// j = 0;
		// while (temp[j] != '\0')
		// 	buffer[i++] = temp[j++];
		// buffer[i] = '\0';
		ft_strlcat(buffer, temp, sizeof(buffer));
	}
	if (buffer[0] == '\0')
		return (NULL);
	line = extract_line(buffer);
	if (line == NULL)
		return (NULL);
	shift_buffer(buffer, find_newline(buffer));
	return (line);
}
int	main()
{
	char	*line;
//fd for file case
	int	fd = open("test_file.txt", O_RDONLY);

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
		printf("2nd print: %s", line);
		line = get_next_line(fd);
		printf("3rd print: %s", line);
		free(line);
	}
		close(fd);
	

/* // stdin case
	while ((line = get_next_line(0)) != NULL)
	{
		printf("%s", line);
		free(line);
	} */

	return (0);
}