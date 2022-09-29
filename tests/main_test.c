/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:59:23 by mpalkov           #+#    #+#             */
/*   Updated: 2022/09/29 14:20:39 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../get_next_line.h"
#include <string.h>
#include <fcntl.h>

char	*get_next_line(int fd);

int main(void)
{
	int		fd;
	char	*theline;
	int		bytes;
	int		bytes_gnl = 0;
//	int		i = 0;
	theline = NULL;
	// 16 files + 1 for NULL termination
	char	*file[17];
	file[1] = "tests/files/41_no_nl";
	


//**************************************
	printf("TEST: textfile\n");
	fd = open(file[1], O_RDONLY);
	printf("file descriptor = %d\n", fd);
	theline = malloc(10009);
	bytes = read(fd, theline, 10009);
	printf("file content(printf):\n%s\n", theline);
	close(fd);
	fd = open("tests/files/textfile.txt", O_RDONLY);
	printf("\n\n--------get next line-------\n");
	while (theline)
	{
	//	printf("----get next line:----\n");
		theline = get_next_line(fd);
		if (!theline)
			printf("get_next_line finished\n\n");
		else
		{
			printf("%s", theline);
			bytes_gnl += strlen(theline);
		}
	//	i++;
	}
	printf("File length %d\nget_next_line read: %d\n\n", bytes, bytes_gnl);
	bytes = 0;
	bytes_gnl = 0;

	return (0);
}
