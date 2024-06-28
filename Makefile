# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 06:19:29 by ymaaloum          #+#    #+#              #
#    Updated: 2024/06/28 06:56:45 by ymaaloum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = 	so_long
SRC1 = 	src/so_long.c \
		src/so_long_utils1.c \
		src/so_long_utils2.c \
		src/so_long_utils3.c \
		src/so_long_utils4.c \
		src/so_long_utils5.c \
		src/so_long_utils6.c \
		src/so_long_utils7.c \
 		src/get_next_line/get_next_line.c\
		src/get_next_line/get_next_line_utils.c \

all: ${NAME}

${NAME}: $(SRC1)
	@${CC} ${CFLAGS} -lmlx -framework OpenGL -framework AppKit ${SRC1}  -o $@

clean:
	@rm -f ${NAME} ${NAME2}

fclean: clean

re: fclean all
