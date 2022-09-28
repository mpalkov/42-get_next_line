/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:12:18 by mpalkov           #+#    #+#             */
/*   Updated: 2022/09/27 12:46:06 by mpalkov          ###   ########.fr       */
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

char	*ft_strdup(char *str)
{
	size_t	len;
	char	*newstr;

	len = ft_strlen(str);
	newstr = (char *)malloc (len + 1);
	if (!newstr)
		return (NULL);
	len = 0;
	while (str[len])
	{
		newstr[len] = str[len];
		len++;
	}
	newstr[len] = '\0';
	return (newstr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*newstr;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	j = 0;
	newstr = (char *)malloc(len1 + len2 + 1);
	if (!newstr)
		return (ft_char_freenull(s1));
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	ft_char_freenull(s1);
	return (newstr);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return (&s[i]);
	else
		return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (!s || start >= (unsigned int)ft_strlen(s) || len == 0)
	{
		newstr = (char *)malloc(1);
		if (!newstr)
			return (NULL);
		newstr[0] = '\0';
		return (newstr);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	newstr = (char *)malloc(len + 1);
	if (!newstr)
		return (NULL);
	while (s[start + (unsigned int)i] && i < len)
	{
		newstr[i] = s[start + (unsigned int)i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
