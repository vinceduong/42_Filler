# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 18:51:58 by vduong            #+#    #+#              #
#    Updated: 2018/09/26 12:16:45 by vduong           ###   ########.fr        #
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
		srcs/free_all.c\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(INCLUDES) $(SRC) $(LIBFT)
	@$(CC) $(FLAGS) -I libft/includes -I includes/ $(SRC) $(LIBFT) -o $(NAME)
	@printf "\n\033[032mCompilation Successful\033[0m\n"
	@printf "\n\033[032mvduong.filler Created\033[0m\n"

$(LIBFT) :
	@make -C visualisateur

clean :
	@make clean -C visualisateur
	@rm -f $(OBJ)

fclean :
	@make fclean -C visualisateur
	@rm -f $(NAME)

re : fclean all
