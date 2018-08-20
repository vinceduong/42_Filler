# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 18:51:58 by vduong            #+#    #+#              #
#    Updated: 2018/08/20 19:07:43 by vduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

CC = GCC

FLAGS = -Wall -Wextra -Werror

NAME = vduong.fillit

LIBFT = libft/libft.a

SRC = srcs/main.c\
	  srcs/get_next_line.c\
	  srcs/fill_map.c\
	  srcs/fill_piece.c\
	  srcs/fill_player.c\
	  srcs/init_map.c\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	make -C libft
	$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)

clean :
	make clean -C libft
	rm -f $(OBJ)

fclean :
	make fclean -C libft
	rm -f $(NAME)

re : fclean all
