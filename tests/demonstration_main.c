/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demonstration_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:35:06 by mpalkov           #+#    #+#             */
/*   Updated: 2022/10/21 15:14:56 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../get_next_line_bonus.h"
#include <string.h>
#include <fcntl.h>

#define FILE1 "tests/files/nl"

typedef struct s_vars
{
int		fd;
char	*file;
int 	i;
char 	*theline;
}                 t_vars;

void  ft_fill(t_vars *b)
{
	b[0].theline = malloc(10);
	b[0].theline[0] = '\0';
	free(b[0].theline);

	b[0].i = 5;
	b[0].file = FILE1;
	b[1].i = 999;
	b[1].file = NULL;
}

void  ft_simplefill(t_vars *a)
{
	a->file = NULL;
	a->i = 42;
	return ;
}

int main() {

t_vars  b[2];

// no le paso fill(&b), porque como es un array, b ya es un mero puntero(una direccion).
ft_fill(b);
ft_simplefill(&b[1]);
return 0;
}
