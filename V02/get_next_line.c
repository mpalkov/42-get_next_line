/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:31:06 by mpalkov           #+#    #+#             */
/*   Updated: 2022/10/11 17:19:54 by mpalkov          ###   ########.fr       */
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

void	*ft_char_freenull(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (NULL);
}

// extract 'till \n (incl). DOES NOT FREE ANYTHING
char	*ft_strtrim1(char *str, ssize_t limit)
{
	char	*newline;
//	ssize_t	len;
	ssize_t	i;
	if (!str || limit < 0)
		return (NULL);
//	len = ft_strlen(str) - limit;
	newline = (char *)malloc(sizeof(char) * (limit + 2));
	if (!newline)
		return (ft_char_freenull(newline));
	i = 0;
	while (str[i] && i <= limit)
	{
		newline[i] = str[i];
		i++;
	}
	newline[i] = '\0';
	return (newline);
}

// extract since \n - FREE BEFORE RETURN
char	*ft_leftover(char *str, ssize_t n_pos)
{
	// "abc\ndef\nghi"
	// n_pos = 3
	// len = 7 = 11 - 4
		
	char	*newline;
	ssize_t	len;
	ssize_t	newlen;
	ssize_t	i;

	i = 0;
	if (!str || n_pos < 0)
		return (NULL);
	len = ft_strlen(str);
	newlen = len - (n_pos + 1);
	newline = (char *)malloc(sizeof(char) * (newlen + 1));
	if (!newline)
		return (ft_char_freenull(newline));
	n_pos++;
	while (str[n_pos] && i <= len)
		newline[i++] = str[n_pos++];
	newline[i] = '\0';
	ft_char_freenull(str);
	return (newline);
}


char	*ft_strjoin(char *s1, char *s2)
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
		return (ft_char_freenull(s1));
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
	jointemp[i + j] = '\0';
	ft_char_freenull(s1);
	return (jointemp);		
}

ssize_t	ft_findchar(char *s, int c)
{
	size_t	i;
	
	i = 0;
	while (s && s[i] && s[i] != (char)c)
		i++;
	if (s && s[i] && s[i] == (char)c)
		return (i);
	else
		return (-1);
}

char	*ft_readnsrch(int fd, char **contsrch, char *buffer, ssize_t *n, ssize_t *b)
{
	*b = -1;
	*b = read(fd, buffer, BUFFER_SIZE);
	buffer[*b] = '\0';
	if (*n < 0 && *b > 0)
	{
		*contsrch = ft_strjoin(*contsrch, buffer);
		if (!*contsrch)
			return (NULL);
		*n = ft_findchar(*contsrch, '\n');
	}
	return (*contsrch);
}	


char	*ft_read(int fd, char **contread, char *line)
{
	char	buffer[BUFFER_SIZE + 1];
	int		i;
	ssize_t	bytes;
	ssize_t	n_pos;

	i = 0;
	n_pos = -1;
	*contread = ft_readnsrch(fd, contread, buffer, &n_pos, &bytes);
	while (n_pos < 0 && bytes > 0)
	{
		if (n_pos == -2)
			return (NULL);
		if (n_pos == -1)
			*contread = ft_readnsrch(fd, contread, buffer, &n_pos, &bytes);
	}
	if (n_pos >=0)
	{
		line = ft_strtrim1(*contread, n_pos);
		if (!line)
			return (NULL);
		*contread = ft_leftover(*contread, n_pos);
		return (line);
	}
	if (bytes <= 0)
	{
		ft_char_freenull(line);
		if (!*contread || bytes < 0 || *contread[0] == '\0')
			return (NULL);
		line = *contread;
	}
	return (line);
}


char	*get_next_line(int fd)
{
	static char	*container = NULL;
	char		*line;
	ssize_t		n_pos;
//	ssize_t		bytes;

	line = NULL;
	if (BUFFER_SIZE < 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	if (container)
	{
		n_pos = ft_findchar(container, '\n');
		if (n_pos >= 0)
		{
			line = ft_strtrim1(container, n_pos);
					if (!line)
						return (ft_char_freenull(container));
			container = ft_leftover(container, n_pos);
			if (!container)
				return (NULL);
			return (line);
		}
	}
	line = ft_read(fd, &container, line);
	if (!line)
		return (ft_char_freenull(container));
	return (line);
}
