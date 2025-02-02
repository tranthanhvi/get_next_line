/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:49:17 by thantran          #+#    #+#             */
/*   Updated: 2025/01/27 21:49:17 by thantran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*read_and_append(int fd, char *remaining);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *remaining, char *buff);
size_t	ft_strlen(char *s);
char	*extract_line(char *remaining);
char	*save_remaining_buffer(char *remaining);

#endif
