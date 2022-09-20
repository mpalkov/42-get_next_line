# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 12:47:00 by mpalkov           #+#    #+#              #
#    Updated: 2022/09/20 15:48:09 by mpalkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



all:
	cc -Wall -Werror -Wextra -g -D BUFFER_SIZE=42 tests/read.c get_next_line.c get_next_line_utils.c

a:
	gcc -Wall -Werror -Wextra -g -D BUFFER_SIZE=42 tests/read.c get_next_line.c get_next_line_utils.c && ./a.out

clean:
	rm -f ./a.out

fclean: clean
