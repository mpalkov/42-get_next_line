/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:24:28 by mpalkov           #+#    #+#             */
/*   Updated: 2022/10/13 11:59:54 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	(int)1;
# endif

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
void	*ft_char_freenull(char *ptr);
char	*get_next_line(int fd);
char    *ft_strtrim1(char *str, ssize_t limit);
char	*ft_leftover(char *str, ssize_t n_pos);
ssize_t	ft_findchar(char *s, int c);
char	*ft_readnsrch(int fd, char **contsrch, char *buffer, ssize_t *n, ssize_t *b);
char	*ft_read(int fd, char **contread, char *line);


#endif
