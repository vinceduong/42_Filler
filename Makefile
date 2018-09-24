# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 18:51:58 by vduong            #+#    #+#              #
#    Updated: 2018/09/24 15:23:57 by carmenia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = vduong.filler


LIBFT = visualisateur/libft/libft.a

SRC = srcs/main.c\
	  srcs/get_next_line.c\
	  srcs/fill_map.c\
	  srcs/fill_piece.c\
	  srcs/fill_player.c\
	  srcs/init_map.c\
	  srcs/init_coor.c\
	  srcs/get_player_coor.c\
	  srcs/sorted_coor.c\
	  srcs/compare_coor.c\
	  srcs/count_symbol.c\
	  srcs/get_valid_coor.c\
	  srcs/enemy_distance.c\
	  srcs/border_distance.c\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(INCLUDES) $(SRC) $(LIBFT)
	@$(CC) $(FLAGS) -I libft/includes -I includes/ $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT) :
	@make -C visualisateur

clean :
	@make clean -C visualisateur
	@rm -f $(OBJ)

fclean :
	@make fclean -C visualisateur
	@rm -f $(NAME)

re : fclean all
