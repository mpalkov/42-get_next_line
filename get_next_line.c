/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:30:25 by mpalkov           #+#    #+#             */
/*   Updated: 2022/10/07 14:07:15 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_char_freenull(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (NULL);
}

static char	*ft_read(int fd, char *container)
{
	int		bytes;
	char	*temp;
	int		i;

	bytes = 1;
	i = 0;
	temp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
	{
//		write(1, "ft_read temp malloc KO", 22);
		return (ft_char_freenull(container));
	}
	while (i < BUFFER_SIZE)
		temp[i++] = '\0';
	if (ft_strlen(container) == 0)
	{
//		write(1, "ft_read container argument is NULL", 31);
//		ft_char_freenull(container);
		return (ft_char_freenull(temp));
	} 

	while (!ft_strchr(container, '\n') && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
//			write(1, "sys read error", 14);
			ft_char_freenull(temp);
			ft_char_freenull(container);
			return (NULL);
		}
		temp[bytes] = '\0';
		container = ft_strjoin(container, temp);
		if (!container)
		{
//			write(1, "ft_read strjoin returned NULL", 29);
			return (ft_char_freenull(temp));
		}
	}
	ft_char_freenull(temp);
	return (container);
}

static char	*ft_leftover(char *container)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = NULL;
	if (!container)
	{
		write(1, "_leftover container argument is NULL", 33);
		return (ft_char_freenull(container));
	}
	while (container[i] != '\n' && container[i] != '\0')
		i++;
	if (container[i] == '\0')
	{
		write(1, "_leftover container[i] == '\0'", 27);
		return (ft_char_freenull(container));
	}
	new = malloc(sizeof(char) * (ft_strlen(container) - i + 1));
	if (!new)
	{
		write(1, "_leftover malloc of new is NULL err", 35);
		ft_char_freenull(container);
		return (ft_char_freenull(new));
	}
	i++;
	while (container[i])
		new[j++] = container[i++];
	new[j] = '\0';
	ft_char_freenull(container);
	return (new);
}	

char	*get_next_line(int fd)
{
	static char	*container = NULL;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
	{
		write(1, "gnl_bad fd or BUFFER_SIZE", 25);
		return (NULL);
	}
	if (!container)
	{
		container = ft_strdup("");
		if (!container)
			return (NULL);
	}
	container = ft_read(fd, container);
	if (!container)
	{
		write(1, "gnl_error in read return", 24);
		return (NULL);
	}
	while (container[i] != '\n' && container[i] != '\0')
		i++;
	line = ft_substr(container, 0, i + 1);
	if (!line)
	{
		write(1, "gnl_substr line returned is NULL", 32);
		if (!container)
			return (NULL);
		else
			return (ft_char_freenull(container));
	}
	container = ft_leftover(container);
	if (ft_strlen(container) == 0)
	{
		write(1, "gnl_containerlength == 0", 16);
		ft_char_freenull(container);
	}
	return (line);
}
