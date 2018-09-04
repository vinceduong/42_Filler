/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:08:05 by vduong            #+#    #+#             */
/*   Updated: 2018/09/04 16:02:04 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

#define PCONTENT piece.content[i][j]

int		border_distance(t_map map, t_piece piece, int *c)
{
	int i;
	int j;
	int distance;
	int tmp1;
	int tmp2;

	distance = -1;
	i = 0;
	while (i < piece.height)
	{
		j = 0;
		while (j < piece.width)
		{
			if (PCONTENT == '*' && map.content[c[0] + i][c[1] + j] == '.')
			{
				tmp1 = map.height - (c[0] + i) > c[0] + i ? c[0] + i : map.height - (c[0] + i);
				tmp2 = map.width - (c[1] + j) > c[0] + i ? c[1] + j : map.width - (c[1] + j);
				tmp1 = tmp1 > tmp2 ? tmp2 : tmp1;
				distance = distance == -1 ? tmp1 : (distance > tmp1 ? tmp1 : distance);
			}
			j++;
		}
		i++;
	}
	return (distance);
}
