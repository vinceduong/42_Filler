# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/26 12:55:52 by vduong            #+#    #+#              #
#    Updated: 2018/09/26 13:41:04 by vduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../filler_viz

CFLAGS = -Wall -Wextra -Werror

INCLUDES = ./includes/

SRC = main.c\
	  image.c\
	  key_hooks.c\
	  game_state_list_utils.c\
	  read_utils.c\
	  render.c\
	  render_str.c\
	  general_utils.c\
	  color.c\

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@gcc $(CFLAGS) -I$(INCLUDES) $(OBJ) -o $(NAME) libft/libft.a /usr/local/lib/libmlx.a -framework OpenGL -framework AppKit
	@printf "\n\033[032mfiller_viz Created\033[0m\n"

%.o: %.c
	@printf "\r\033[31mgcc -c -Wall -Wextra -Werror -o $@ $^                    \033[0m"
	@gcc -c -Wall -Wextra -Werror -o $@ $^

$(LIBFT):
	@make -C libft

clean:
	@cd libft ; make clean ; cd ..
	@rm -f $(OBJ)


fclean: clean
	@cd libft ; make fclean ; cd ..
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
