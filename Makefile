# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 12:47:00 by mpalkov           #+#    #+#              #
#    Updated: 2022/09/20 12:53:17 by mpalkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 tests/read.c get_next_line.c get_next_line_utils.c && ./a.out
