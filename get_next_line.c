/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:30:25 by mpalkov           #+#    #+#             */
/*   Updated: 2022/09/22 14:17:45 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *buffer)
{
	int	bytes;
	char *temp;

	bytes = 1;
	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	temp[0] = '\0';
	while (!ft_strchr(buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[bytes] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

static char	*ft_leftover(char *buffer)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new = malloc(sizeof(char) * ft_strlen(buffer) - i + 1);
	i++;
	if (!new)
	{
		free(new);
		return (NULL);
	}
	while (buffer[i])
		new[j++] = buffer[i++];
	new[j] = '\0';
	free(buffer);
	return (new);
}

char		*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_strdup("");
		if (!buffer)
		{
			free(buffer);
			return (NULL);
		}
	}	
	buffer = ft_read(fd, buffer);
	if (!buffer)
	{
		free (buffer);
		return (NULL);
	}
	while(buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = ft_substr(buffer, 0, i + 1);
	buffer = ft_leftover(buffer);
	// if (!line || !line[0]) ???
	if (!line || !line[0])
	{
		free (line);
		return (NULL);
	}
//
//printf("line:\n%s", line);
	return (line);
}

