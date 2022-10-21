/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:59:23 by mpalkov           #+#    #+#             */
/*   Updated: 2022/10/21 17:25:58 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../get_next_line_bonus.h"
#include <string.h>
#include <fcntl.h>

// number of files used for testing
#define MAXFILES (int)15

#define FILE1 "tests/files/nl"
#define FILE2 "tests/files/alternate_line_nl_with_nl"
#define FILE3 "tests/files/textfile.txt"
#define FILE4 "tests/files/empty"
#define FILE5 "tests/files/42_with_nl";
#define FILE6 "tests/files/43_with_nl";
#define FILE7 "tests/files/alternate_line_nl_no_nl";
#define FILE8 "tests/files/alternate_line_nl_with_nl";
#define FILE9 "tests/files/42_no_nl";
#define FILE10 "tests/files/43_no_nl";
#define FILE11 "tests/files/41_no_nl";
#define FILE12 "tests/files/multiple_line_no_nl";
#define FILE13 "tests/files/multiple_line_with_nl";
#define FILE14 "tests/files/big_line_no_nl";
#define FILE15 "tests/files/big_line_with_nl";

char	*ft_freenull(char **ptr)
{
	if(*ptr)
		free(*ptr);
	*ptr = NULL;
	return (NULL);
}

typedef struct	s_vars
{
	int		fd;
	char	*file;
	char	*theline;
	int		bytes;
	int		bytes_gnl;
	char	*gnljoin;
	char	*origfile;
	int		ok;
	int		finished;
}				t_vars;

char	*get_next_line(int fd);
int		gnl_test(t_vars *vars, int f);

char	*ft_strdupp(char *str)
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

void	ft_initfiles(t_vars *vars)
{
	int i = 0;

	vars[0].file = FILE1;
	vars[1].file = FILE2;
	vars[2].file = FILE3;
	vars[3].file = FILE4;
	vars[4].file = FILE5;
	vars[5].file = FILE6;
    vars[6].file = FILE7;
    vars[7].file = FILE8;
    vars[8].file = FILE9; 
    vars[9].file = FILE10;
	vars[10].file = FILE11;
    vars[11].file = FILE12;
    vars[12].file = FILE13;
    vars[13].file = FILE14;
    vars[14].file = FILE15;
//    vars[15].file = NULL;
	
	while (i < MAXFILES)
	{
		vars[i].fd = -1;
		vars[i].bytes = 0;
		vars[i].bytes_gnl = 0;
		vars[i].gnljoin = NULL;
		vars[i].origfile = NULL;
		vars[i].ok = 0;
		vars[i].finished = 0;

		vars[i].fd = open(vars[i].file, O_RDONLY);
		vars[i].theline = malloc(10010);
		vars[i].bytes = read(vars[i].fd, vars[i].theline, 10009);
		vars[i].theline[vars[i].bytes] = '\0';
		vars[i].origfile = ft_strdupp(vars[i].theline);
		close(vars[i].fd);
		ft_freenull(&vars[i].theline);
		vars[i].fd = open(vars[i].file, O_RDONLY);

		i++;
	}
	return ;
}

int	ft_alldone(t_vars *vars)
{
	int	i = 0;

	while(i < MAXFILES)
	{
		if (!vars[i].file)
			return (1);
		if (!vars[i].finished)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_gnl_finalcheck(t_vars *vars, int f)
{
	int	cmp = -1;
	
	printf("\nget_next_line finished\n");
	printf("File length %d\nget_next_line read: %d\n", vars[f].bytes, vars[f].bytes_gnl);
	if (vars[f].gnljoin && vars[f].origfile)
	{
		cmp = strcmp(vars[f].gnljoin, vars[f].origfile);
		printf("strcmp:%d\n\n", cmp);
		if (vars[f].bytes == vars[f].bytes_gnl && !cmp)
		{ 
			printf("OK\n");
			vars[f].ok = 1;
		}
		else
		{
			printf("MAL\n");
			vars[f].ok = 0;
		}
	}
	return (0);
}

int gnl_test(t_vars *vars, int f)
{
	if (vars[f].finished)
		return (1);
	else
	{
		printf("\n\n--------get next line, file[%i]:\n", f);
		vars[f].theline = get_next_line(vars[f].fd);
		vars[f].bytes_gnl += ft_strlen(vars[f].theline);
		vars[f].gnljoin = ft_strjoin(vars[f].gnljoin, vars[f].theline);
		
		if (!vars[f].theline)
		{
			vars[f].finished = 1;
			ft_gnl_finalcheck(vars, f);
			ft_freenull(&vars[f].theline);
			return (1);
		}
		printf("%s\n", vars[f].theline);
		return (1);
	}
	return (1);
}

int main(void)
{
	t_vars	vars[MAXFILES];
	int		f = 0;

	ft_initfiles(vars);

	while (!ft_alldone(vars))
	{
		// the vars[f].file check is if I want to stop the tests at some point
		// before all files finish testing. 
		while (f < MAXFILES && vars[f].file)
		{
			if (vars[f].finished != 1)
				gnl_test(vars, f);
			f++;
		}
		f = 0;
	}
	
	printf("\n----------\nALL TESTS FINISHED\n\n1 == OK | 0 == MAL\n");
	f = 0;
	while (f < MAXFILES)
	{
		printf("TEST %d == %d\n", f, vars[f].ok);
		f++;
	}
	printf("------------ END ------------\n");
	return (0);
}
