/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:59:23 by mpalkov           #+#    #+#             */
/*   Updated: 2022/09/30 13:40:02 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../get_next_line.h"
#include <string.h>
#include <fcntl.h>

char	*get_next_line(int fd);
int gnl_test(char *file, int *ok);

int main(void)
{
	int		i = 0;
	int		ok[17];
	// 16 files + 1 for NULL termination
	char	*file[17];
	file[0] = "tests/files/41_no_nl";
	file[1] = "tests/files/41_with_nl";
	file[2] = "tests/files/42_no_nl";
	file[3] = "tests/files/42_with_nl";
	file[4] = "tests/files/43_no_nl";
	file[5] = "tests/files/43_with_nl";
	file[6] = "tests/files/alternate_line_nl_no_nl";
	file[7] = "tests/files/alternate_line_nl_with_nl";
//	file[14] = "tests/files/big_line_no_nl";
//	file[15] = "tests/files/big_line_with_nl";
	file[10] = "tests/files/empty";
	file[11] = "tests/files/multiple_line_no_nl";
	file[12] = "tests/files/multiple_line_with_nl";
	file[13] = "tests/files/multiple_nlx5";
	file[8] = "tests/files/nl";
	file[9] = "tests/files/textfile.txt";
	file[16] = NULL;


	while (file[i])
	{
		gnl_test(file[i], &ok[i]);
		i++;
	}
	if (file[i] == NULL)
		ok[i] = -1;
	printf("\n----------\nALL TESTS FINISHED\n\n1 == OK | 0 == MAL | -1 == END OF TESTS\n");
	while (i >= 0)
	{
		printf("TEST %d == %d\n", i, ok[i]);
		i--;
	}
	return (0);
}

int gnl_test(char *file, int *ok)
{
	int		fd;
	char	*theline;
	int		bytes;
	int		bytes_gnl = 0;

	theline = NULL;
	printf("--------------------------------------\nTEST: %s\n", file);
	fd = open(file, O_RDONLY);
//	printf("file descriptor = %d\n", fd);
	theline = malloc(10009);
	bytes = read(fd, theline, 10009);
	printf("file content(printf):\n%s", theline);
	close(fd);
	fd = open(file, O_RDONLY);
	printf("\n\n--------get next line\n");
	while (theline)
	{
		theline = get_next_line(fd);
		if (!theline)
			printf("\nget_next_line finished\n");
		else
		{
			printf("%s", theline);
			bytes_gnl += strlen(theline);
		}
	}
	printf("File length %d\nget_next_line read: %d\n\n", bytes, bytes_gnl);
	if (bytes == bytes_gnl)
	{
		printf("OK\n");
		*ok = 1;
	}
	else
	{
		printf("MAL\n");
		*ok = 0;
	}
	bytes = 0;
	bytes_gnl = 0;
	free(theline);
	return (0);
}

