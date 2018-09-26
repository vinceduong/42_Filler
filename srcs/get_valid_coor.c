/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_coor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 11:31:11 by vduong            #+#    #+#             */
/*   Updated: 2018/09/17 16:01:37 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define PCONTENT	piece.content[y][x]
#define MCONTENT	map.content[coor[0] + y][coor[1] + x]

int		is_placable(t_map map, t_piece piece, char symbol, int *coor)
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
			if (PCONTENT == '*' &&
				((coor[0] + y >= map.height) || coor[1] + x >= map.width))
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
	int		*coor;

	i = -1;
	count = 0;
	coor = (int *)malloc(2 * sizeof(int));
	while (i++ < map.height)
	{
		j = -1;
		while (j++ < map.width)
		{
			coor[0] = i;
			coor[1] = j;
			count += is_placable(map, piece, symbol, coor);
		}
	}
	free(coor);
	return (count);
}

int		**fill_valid_coor(t_map map, t_piece piece, char symbol, int **vc)
{
	int		i;
	int		j;
	int		nb;
	int		*c;

	nb = 1;
	i = -1;
	c = (int *)malloc(2 * sizeof(int));
	while (i++ < map.height)
	{
		j = -1;
		while (j++ < map.width)
		{
			c[0] = i;
			c[1] = j;
			if (is_placable(map, piece, symbol, c))
			{
				vc[nb][0] = i;
				vc[nb][1] = j;
				nb++;
			}
		}
	}
	free(c);
	return (vc);
}

int		**get_valid_coor(t_map map, t_piece piece, char symbol)
{
	int		**coor;

	if (!(coor = init_coor(count_placable_coor(map, piece, symbol), 1)))
		return (NULL);
	return (fill_valid_coor(map, piece, symbol, coor));
}
