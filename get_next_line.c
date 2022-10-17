/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:30:25 by mpalkov           #+#    #+#             */
/*   Updated: 2022/10/17 16:21:02 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_char_freenull(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (NULL);
}

static char	*ft_read(int fd, char *readbuff)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	temp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (ft_char_freenull(&readbuff));
	while (!ft_strchr(readbuff, '\n') && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			ft_char_freenull(&temp);
			ft_char_freenull(&readbuff);
			return (NULL);
		}
		temp[bytes] = '\0';
		readbuff = ft_strjoin(readbuff, temp);
		if (!readbuff)
			return (ft_char_freenull(&temp));
	}
	ft_char_freenull(&temp);
	return (readbuff);
}

static char	*ft_leftover(char *leftbuff)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!leftbuff)
		return (NULL);
//		return (ft_char_freenull(leftbuff));
	while (leftbuff[i] != '\n' && leftbuff[i] != '\0')
		i++;
	if (leftbuff[i] == '\0')
	{
		ft_char_freenull(&leftbuff);
		leftbuff = ft_strdup("");
		if (!leftbuff)
			return (NULL);
		return (leftbuff);
	}
//		i = 0;
	new = malloc(sizeof(char) * ft_strlen(leftbuff) - i + 1);
	if (!new)
		return (ft_char_freenull(&leftbuff));
	i++;
	while (leftbuff[i])
		new[j++] = leftbuff[i++];
	new[j] = '\0';
	ft_char_freenull(&leftbuff);
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
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = ft_substr(buffer, 0, i + 1);
	if (!line)
		return (ft_char_freenull(&buffer));
	buffer = ft_leftover(buffer);
	if (!buffer)
		return (ft_char_freenull(&line));
	if (buffer[0] == '\0')
		buffer = ft_char_freenull(&buffer);
	if (line[0] == 0)
	{
		return (ft_char_freenull(&line));
	}
	return (line);
}
