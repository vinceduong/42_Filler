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

int		distance(int c1, int c2, int C1, int C2)
{
	return (abs(c1 - C1) + abs(c2 - C2));
}

int		enemy_distance(t_map map, t_piece piece, int **en_c, int *c)
{
	int	n;
	int i;
	int j;
	int	dist;
	int tmp;

	n = 1;
	dist = -1;
	while (n < en_c[0][0] + 1)
	{
		i = 0;
		while (i < piece.height)
		{
			j = 0;
			while (j < piece.width)
			{
				if (PCONTENT == '*' && map.content[c[0] + i][c[1] + j] == '.')
				{
					tmp = distance(en_c[n][0], en_c[n][1], c[0], c[1]);
					dist = tmp < dist || dist == -1 ? tmp : dist;
				}
				j++;
			}
			i++;
		}
		n++;
	}
	return (dist);
}
