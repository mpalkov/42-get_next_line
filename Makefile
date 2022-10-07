# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 12:47:00 by mpalkov           #+#    #+#              #
#    Updated: 2022/10/07 11:27:09 by mpalkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



all:
	cc -Wall -Werror -Wextra -g -D BUFFER_SIZE=42 tests/read.c get_next_line.c get_next_line_utils.c

s:
	gcc -Wall -Werror -Wextra -fsanitize=address -g -static-libsan -D BUFFER_SIZE=5 tests/read.c get_next_line.c get_next_line_utils.c -o sanit_test.out && ./sanit_test.out

a:
	gcc -Wall -Werror -Wextra -g -D BUFFER_SIZE=5 tests/read.c get_next_line.c get_next_line_utils.c -o readtest.out && ./readtest.out

t:
	cc -Wall -Werror -Wextra -g -D BUFFER_SIZE=100 tests/main_test.c get_next_line.c get_next_line_utils.c -o readtest.out && ./readtest.out

nbonus:
	cc -Wall -Werror -Wextra -g -D BUFFER_SIZE=42 tests/read.c get_next_line_bonus.c get_next_line_utils_bonus.c

tbonus:
	cc -Wall -Werror -Wextra -g -D BUFFER_SIZE=10000 tests/main_test.c get_next_line_bonus.c get_next_line_utils_bonus.c -o readtest_bonus.out && ./readtest_bonus.out

clean:
	rm -f ./a.out

fclean: clean
