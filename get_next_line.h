/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:24:28 by mpalkov           #+#    #+#             */
/*   Updated: 2022/10/17 15:26:16 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

//retirar
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	(int)1;
# endif

char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
void	*ft_char_freenull(char **ptr);

#endif
