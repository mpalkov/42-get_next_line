/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:30:25 by mpalkov           #+#    #+#             */
/*   Updated: 2022/10/19 12:21:51 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// This has to receive the argument as double pointer,
// because if just a simple pointer is received the ptr = NULL
// will not have effect on the actual char * after function ft_char_freenull
// terminates.
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

// if (leftbuff[i] == '\0') has no explicit ft_strdup's malloc protection,
// because leftbuff is always returned
// and so if (!leftbuff), return(leftbuff) returns actually the NULL.
static char	*ft_leftover(char *leftbuff)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!leftbuff)
		return (NULL);
	while (leftbuff[i] != '\n' && leftbuff[i] != '\0')
		i++;
	if (leftbuff[i] == '\0')
	{
		ft_char_freenull(&leftbuff);
		leftbuff = ft_strdup("");
		return (leftbuff);
	}
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

static char	*ft_finalchecks(char **buffer, char **line)
{
	if (!(*buffer))
		return (ft_char_freenull(line));
	if (*buffer[0] == '\0')
		*buffer = ft_char_freenull(buffer);
	if (*line[0] == '\0')
		return (ft_char_freenull(line));
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
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
	return (ft_finalchecks(&buffer, &line));
}
