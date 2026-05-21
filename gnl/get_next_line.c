/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-17 17:54:47 by vihardy           #+#    #+#             */
/*   Updated: 2026-02-17 17:54:47 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*free_null(char *s1, char *buffer)
{
	free(s1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	return (NULL);
}

static char	*read_to_buffer(int fd, char *buffer)
{
	char		*res;
	ssize_t		bytes_read;

	res = ft_strdup(buffer);
	if (!res)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_null(res, buffer));
		buffer[bytes_read] = '\0';
		res = ft_strjoin(res, buffer);
		if (!res)
			return (NULL);
	}
	if (bytes_read == 0 && res[0] == '\0')
		return (free_null(res, buffer));
	return (res);
}

static char	*extract_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static void	update_buffer(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		return ;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*res;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = read_to_buffer(fd, buffer);
	if (!res)
		return (NULL);
	if (res[0] == '\0')
	{
		free(res);
		return (NULL);
	}
	line = extract_line(res);
	update_buffer(buffer);
	free(res);
	return (line);
}
