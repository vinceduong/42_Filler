/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_coor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 10:57:34 by vduong            #+#    #+#             */
/*   Updated: 2018/08/22 15:59:49 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

#define ABS(X)	(X > 0 ? X : -X)
#define PCONTENT piece.content[i][j]

int		distance(int c1, int c2, int C1, int C2)
{
	return (ABS(c1 - C1) - ABS(c2 - C2));
}

int		enemy_distance(int **en_c, t_piece piece, int *c)
{
	int	n;
	int i;
	int j;
	int	dist;
	int tmp;

	n = 1;
	dist = 0;
	while (n < en_c[0][0] + 1)
	{
		i = 0;
		while (i < piece.height)
		{
			j = 0;
			while (j < piece.width)
			{
				if (PCONTENT == '*')
				{
					tmp = distance(en_c[n][0], en_c[n][1], c[0] + i, c[1] + j);
					dist = tmp > dist ? tmp : dist;
				}
				j++;
			}
			i++;
		}
		n++;
	}
	return (dist);
}

int		compare_coor(int **en_c, t_piece piece, int *c1, int *c2)
{
	return (enemy_distance(en_c, piece, c1) >= enemy_distance(en_c, piece, c2));
}
