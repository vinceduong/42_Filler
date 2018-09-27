# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 18:51:58 by vduong            #+#    #+#              #
#    Updated: 2018/09/26 13:27:54 by vduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = vduong.filler

VIZ = filler_viz

LIBFT = libft/libft.a

INCLUDES = -I./libft/includes/ -I./includes/

SRC = srcs/main.c\
	  srcs/get_next_line.c\
	  srcs/fill_map.c\
	  srcs/fill_piece.c\
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

allclean : all clean

$(NAME) : $(LIBFT) $(SRC) $(LIBFT)
	@$(CC) $(FLAGS) $(INCLUDES) $(SRC) $(LIBFT) -o $(NAME)
	@printf "\n\033[032mFiller Compilation Successful\033[0m\n"
	@printf "\n\033[032mPlayer \"vduong.filler\" Created\033[0m\n"

$(LIBFT) :
	@make -C libft

$(VIZ) :
	@make -C visualisateur

clean :
	@make clean -C visualisateur
	@make clean -C libft
	@rm -f $(OBJ)

fclean :
	@make fclean -C visualisateur
	@make clean -C libft
	@rm -f $(NAME) filler_viz
	@printf "\n\033[032mPlayer \"vduong.filler\" Deleted\033[0m\n"

re : fclean all
