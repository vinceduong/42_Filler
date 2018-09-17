/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:08:05 by vduong            #+#    #+#             */
/*   Updated: 2018/09/07 14:34:43 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

#define PCONTENT piece.content[i][j]
#define	MCONTENT	map.content[i][j]
#define I       en_c[i][0]
#define J       en_c[i][1]

int		*enemy_borders(t_map map, int **en_c)
{
	int *borders;
	int i;
	int heightdist;
	int widthdist;

	heightdist = 1000000;
	widthdist = 1000000;
	borders = (int *)malloc(sizeof(int) * 2);
	i = 1;
	while (i < en_c[0][0])
	{
		if ((map.height - I > I ? I : map.height - I) < heightdist)
		{
			borders[0] = map.height - I > I ? 0 : 1;
			heightdist = map.height - I > I ? I : map.height - I;
		}
		if ((map.width - J > J ? J : map.width - J) < widthdist)
		{
			borders[1] = map.width - J > J ? 0 : 1;
			widthdist = map.width - J > J ? J : map.height - J;
		}
		i++;
	}
	return (borders);
}

int		*border_distance(t_map map, t_piece piece, int **en_c, int *c)
{
	int i;
	int j;
	int *e_borders;
	int *dist;
	int tmp;

	e_borders = enemy_borders(map, en_c);
	dist = (int *)malloc(sizeof(int) * 2);
	/*printf("e_borders[0] = %d\n", e_borders[0]);
	printf("e_borders[1] = %d\n", e_borders[1]);*/
	i = 0;
	dist[0] = 100000;
	dist[1] = 100000;
	while (i < piece.height)
	{
		j = 0;
		while (j < piece.width)
		{
			if (PCONTENT == '*' && map.content[c[0] + i][c[1] + j] == '.')
			{
				tmp = !e_borders[0] ? c[0] + i : map.height - (c[0] + i);
				dist[0] = tmp < dist[0] ? tmp : dist[0];
				tmp = !e_borders[1] ? c[1] + j : map.width - (c[1] + j);
				dist[1] = tmp < dist[1] ? tmp : dist[1];
			}
			j++;
		}
		i++;
	}
	return (dist);
}
