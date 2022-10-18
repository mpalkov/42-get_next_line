# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 12:47:00 by mpalkov           #+#    #+#              #
#    Updated: 2022/10/18 15:11:00 by mpalkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



all:
	cc -Wall -Werror -Wextra -g -D BUFFER_SIZE=42 tests/main_test.c get_next_line.c get_next_line_utils.c

s:
	gcc -Wall -Werror -Wextra -fsanitize=address -g -static-libsan -D BUFFER_SIZE=5 tests/read.c get_next_line.c get_next_line_utils.c -o sanit_test.out && ./sanit_test.out

a:
	gcc -Wall -Werror -Wextra -g -D BUFFER_SIZE=5 tests/main_test.c get_next_line.c get_next_line_utils.c -o readtest.out && ./readtest.out

t:
	cc -Wall -Werror -Wextra -g -D BUFFER_SIZE=100 tests/main_test.c get_next_line.c get_next_line_utils.c -o readtest.out && ./readtest.out

bonus:
	cc -Wall -Werror -Wextra -g -D BUFFER_SIZE=42 tests/main_test_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c -o bonus.out && ./bonus.out


clean:
	rm -f ./a.out

fclean: clean
