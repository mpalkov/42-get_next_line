/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:30:25 by mpalkov           #+#    #+#             */
/*   Updated: 2022/09/16 18:13:27 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *ptr)
{
	int	bytes;
	char *temp;

	bytes = 1;
	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while(!ft_strchr(ptr, (int)'\n') && bytes != '\0')
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == 0)
		{
			free(temp);
			free(ptr);
			return (NULL);
		}
		temp[bytes] = '\0';
		ptr = ft_strjoin(ptr, temp);
	}
	free(temp);
	return (ptr);
}

char		*get_next_line(int fd)
{
	static char	*ptr;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ptr)
		ptr = ft_strdup("");
	ptr = ft_read(fd, ptr);
	if (!ptr)
		return (NULL);
	while(ptr[i] != '\n' && ptr[i] != '\0')
		i++;
	line = malloc(ft_strlen(



}

