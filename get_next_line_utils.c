/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantran <thantran@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:49:28 by thantran          #+#    #+#             */
/*   Updated: 2025/01/27 21:49:28 by thantran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *remaining, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!remaining)
	{
		remaining = (char *)malloc(1 * sizeof(char));
		remaining[0] = '\0';
	}
	if (!remaining || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(remaining) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (remaining)
		while (remaining[++i] != '\0')
			str[i] = remaining[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(remaining) + ft_strlen(buff)] = '\0';
	free(remaining);
	return (str);
}

char	*extract_line(char *remaining)
{
	int		i;
	char	*str;

	i = 0;
	if (!remaining[i])
		return (NULL);
	while (remaining[i] && remaining[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (remaining[i] && remaining[i] != '\n')
	{
		str[i] = remaining[i];
		i++;
	}
	if (remaining[i] == '\n')
	{
		str[i] = remaining[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*save_remaining_buffer(char *remaining)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (remaining[i] && remaining[i] != '\n')
		i++;
	if (!remaining[i])
	{
		free(remaining);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(remaining) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (remaining[i])
		str[j++] = remaining[i++];
	str[j] = '\0';
	free(remaining);
	return (str);
}
