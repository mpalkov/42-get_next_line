/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:31:06 by mpalkov           #+#    #+#             */
/*   Updated: 2022/10/07 15:52:40 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *ft_char_freetemp(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (NULL);
}

char *ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*jointemp;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	jointemp = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!jointemp)
		return (ft_char_freetemp(s1));
	while (s1 && s1[i])
	{
		jointemp[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		jointemp[i + j] = s2[j];
		j++;
	}
	jointemp[i + j + 1] = '\0';
	ft_char_freetemp(s1);
	return (jointemp);		
}

ssize_t	ft_findchar(char *s, int c)
{
	size_t	i;
	
	i = 0;
	while (s && s[i] != (char)c)
		i++;
	if (s && s[i] == (char)c)
		return (i);
	else
		return (-1);
}

char *ft_found_n(char *str, ssize_t n_pos)
{
// ACABAR
}


ft_read(int fd, char *container)
{
	char	buffer[BUFFER_SIZE + 1];
	int		i;
	int		bytes;
	ssize_t	n_pos;

	i = 0;
	bytes = 1;
	read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\0';
	
	container = ft_strjoin(container, buffer);
	if (!container)
		return (NULL);
	n_pos = ft_findchar(container, '\n');
	if (n_pos == -1)
		//vuelve a hacer el read y join
	else
	{
// ACABAR
	}

	


}

char	*ft_extractline(char *str, ssize_t pos)
{
	char	*newline;
	ssize_t	len;

	if (!str || pos < 0)
		return (ft_char_freenull(newline));

// ACABAR


}

char	*get_next_line(int fd)
{
	static char	*container = NULL;
	char		*line;
	ssize_t		n_pos;

	if (BUFFER_SIZE < 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	n_pos = ft_findchar(container, '\n');
	if (n_pos != -1)
	{
		line = ft_extractline(container, n_pos);
		if (!line)
			// ACABAR
	}
	line = ft_read(fd, container);
	if (!line)
		return (NULL);



	return ();
}
