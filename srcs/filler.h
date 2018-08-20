/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:10:36 by vduong            #+#    #+#             */
/*   Updated: 2018/08/20 17:47:23 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include	"../libft/libft.h"
#include	"get_next_line.h"
#include <stdio.h>

typedef	struct	 s_piece
{
	int		height;
	int		width;
	char	**content;
}				t_piece;

typedef	struct	s_map
{
	int		height;
	int		width;
	char	**content;
}				t_map;

typedef	struct	s_player
{
	int		number;
	char	*name;
	char	symbol;
}				t_player;


int				fill_map(t_map *map);
int				fill_piece(t_piece *piece);
int				fill_player(t_player *player, char *firstline);
int				free_map(t_map *map);
int				free_piece(t_piece *piece);
char			**init_map(char **map, int height, int width);
#endif
