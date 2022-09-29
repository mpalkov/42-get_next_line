/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:24:30 by mpalkov           #+#    #+#             */
/*   Updated: 2022/09/23 15:08:08 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

char	*get_next_line(int fd);

int main(void)
{
	int		fd;
	char	*theline;
//	int		bytes;
	int		i = 0;

	theline = NULL;	
	fd = open("tests/textfile.txt", O_RDONLY);
	//printf("file descriptor = %d\n", fd);
	theline = malloc(999);
//	bytes = read(fd, theline, 999);
//	printf("CONTENT:\n%s\nbytes read: %d", theline, bytes);
	while (theline)
	{
		//printf("----next line:----\n");
		theline = get_next_line(fd);
		//printf("%s", theline);
		i++;
	}
	return (0);
}
