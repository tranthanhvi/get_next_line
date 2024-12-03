/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:15:39 by thantran          #+#    #+#             */
/*   Updated: 2024/12/01 16:13:29 by thantran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> // for open() read() close() perror()
# include <stdlib.h> // for malloc() free()
# include <stdio.h> // REMOVE THIS
# include <fcntl.h>


# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 42;
# endif
char	*get_next_line(int fd);
int	find_newline(char *buffer);
char *extract_line(char *buffer);
void	shift_buffer(char *buffer, int index);



#endif