# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 12:47:00 by mpalkov           #+#    #+#              #
#    Updated: 2022/09/22 14:13:28 by mpalkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



all:
	cc -Wall -Werror -Wextra -g -D BUFFER_SIZE=42 tests/read.c get_next_line.c get_next_line_utils.c

s:
	gcc -Wall -Werror -Wextra -fsanitize=address -g -static-libsan -D BUFFER_SIZE=5 tests/read.c get_next_line.c get_next_line_utils.c -o sanit_test.out && ./sanit_test.out

a:
	gcc -Wall -Werror -Wextra -g -D BUFFER_SIZE=5 tests/read.c get_next_line.c get_next_line_utils.c -o readtest.out && ./readtest.out


clean:
	rm -f ./a.out

fclean: clean
