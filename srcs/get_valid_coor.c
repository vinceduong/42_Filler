/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_coor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 11:31:11 by vduong            #+#    #+#             */
/*   Updated: 2018/09/05 14:00:32 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

#define  PCONTENT piece.content[y][x]
#define  MCONTENT map.content[i + y][j + x]

int		is_placable(t_map map, t_piece piece, char symbol, int i, int j)
{
	int	nbover;
	int	x;
	int y;

	nbover = 0;
	y = 0;
	while (y < piece.height)
	{
		x = 0;
		while (x < piece.width)
		{
			if (PCONTENT == '*' && ((i + y >= map.height) || j + x >= map.width))
				return (0);
			if (PCONTENT == '*' && MCONTENT == symbol)
				nbover++;
			if (PCONTENT == '*' && MCONTENT != '.' && MCONTENT != symbol)
				return (0);
			x++;
		}
		y++;
	}
	return (nbover == 1);
}

int		count_placable_coor(t_map map, t_piece piece, char symbol)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			count += is_placable(map, piece, symbol, i, j);
			j++;
		}
		i++;
	}
	return (count);
}

int		**get_valid_coor(t_map map, t_piece piece, char symbol)
{
	int		**coor;
	int		i;
	int		j;
	int		nb;

	if (!(coor = init_coor(count_placable_coor(map, piece, symbol), 3)))
		return (NULL);
	nb = 1;
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (is_placable(map, piece, symbol, i, j))
			{
				coor[nb][0] = i;
				coor[nb][1] = j;
				nb++;
			}
			j++;
		}
		i++;
	}
	return (coor);
}
