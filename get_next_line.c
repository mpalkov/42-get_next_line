/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:30:25 by mpalkov           #+#    #+#             */
/*   Updated: 2022/10/03 16:46:34 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_char_freenull(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (NULL);
}

static char	*ft_read(int fd, char *buffer)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	temp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (ft_char_freenull(buffer));
	while (!ft_strchr(buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			ft_char_freenull(temp);
			ft_char_freenull(buffer);
			return (NULL);
		}
		temp[bytes] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (!buffer)
			return (ft_char_freenull(temp));
	}
	ft_char_freenull(temp);
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
		return (ft_char_freenull(buffer));
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		return (ft_char_freenull(buffer));
	new = malloc(sizeof(char) * ft_strlen(buffer) - i + 1);
	i++;
	if (!new)
	{
		ft_char_freenull(buffer);
		return (ft_char_freenull(new));
	}
	while (buffer[i])
		new[j++] = buffer[i++];
	new[j] = '\0';
	ft_char_freenull(buffer);
	return (new);
}	

char	*get_next_line(int fd)
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
			return (NULL);
	}
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (ft_char_freenull(buffer));
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = ft_substr(buffer, 0, i + 1);
	buffer = ft_leftover(buffer);
	if (!line || !line[0])
		return (ft_char_freenull(line));
	return (line);
}
