/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_distance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:03:34 by vduong            #+#    #+#             */
/*   Updated: 2018/09/17 16:52:30 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define ABS(X)		(X > 0 ? X : -X)
#define PCONTENT	piece.content[i][j]

int		abs(int n)
{
	return (n < 0 ? -n : n);
}

int		distance(int c1, int c2, int j1, int j2)
{
	return (abs(c1 - j1) + abs(c2 - j2));
}

int		coor_distance(t_map map, t_piece piece, int *en_c, int *c)
{
	int i;
	int j;
	int	dist;
	int tmp;

	dist = -1;
	i = 0;
	while (i < piece.height)
	{
		j = 0;
		while (j < piece.width)
		{
			if (PCONTENT == '*' && map.content[c[0] + i][c[1] + j] == '.')
			{
				tmp = distance(en_c[0], en_c[1], c[0] + i, c[1] + j);
				dist = tmp < dist || dist == -1 ? tmp : dist;
			}
			j++;
		}
		i++;
	}
	return (dist);
}

int		enemy_distance(t_map map, t_piece piece, int **en_c, int *c)
{
	int	n;
	int	dist;
	int tmp;

	n = 1;
	dist = -1;
	while (n < en_c[0][0] + 1)
	{
		if ((tmp = coor_distance(map, piece, en_c[n], c)) < dist || dist == -1)
			dist = tmp;
		n++;
	}
	return (dist);
}
