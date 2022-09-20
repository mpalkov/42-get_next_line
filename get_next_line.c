/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:30:25 by mpalkov           #+#    #+#             */
/*   Updated: 2022/09/20 13:04:11 by mpalkov          ###   ########.fr       */
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
	while(!ft_strchr(buffer, (int)'\n') && bytes != '\0')
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == 0)
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
	static char	*buffer[OPEN_MAX];
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > OPEN_MAX)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	buffer = ft_read(fd, buffer);
	if (!buffer)
	{
		free (buffer);
		return (NULL);
	}
	while(buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = ft_substr(ptr, 0, i + 1);
	buffer = ft_leftover(ptr);
	// if (!line || !line[0]) ???
	if (!line)
	{
		free (line);
		return (NULL);
	}







}

