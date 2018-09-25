/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_coor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:38:39 by vduong            #+#    #+#             */
/*   Updated: 2018/09/17 16:47:29 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_coor(int **coor)
{
	int i;
	int n;

	i = 0;
	n = coor[0][0];
	if (coor)
	{
		while (i <= n && coor[i])
		{
			free(coor[i]);
			i++;
		}
		free(coor);
	}
}

int	*sort_coor(int **v_coor)
{
	int i;
	int *tmp;

	tmp = (int *)malloc(sizeof(int) * 2);
	i = 1;
	while (i < v_coor[0][0])
	{
		if (compare_coor(v_coor[i], v_coor[i + 1]))
		{
			tmp = v_coor[i];
			v_coor[i] = v_coor[i + 1];
			v_coor[i + 1] = tmp;
			i = 1;
		}
		else
			i++;
	}
	if (!v_coor[1])
		return (NULL);
	tmp[0] = v_coor[1][0];
	tmp[1] = v_coor[1][1];
	return (tmp);
}

int	*sorted_coor(t_map map, t_piece piece, char symbol)
{
	int **v_coor;
	int **e_coor;
	int	i;
	int	*best;

	if (!(v_coor = get_valid_coor(map, piece, symbol)) || !v_coor[0][0])
		return (NULL);
	if (!(e_coor = get_player_coor(map, symbol == 'O' ? 'X' : 'O')))
		return (NULL);
	i = 1;
	while (i <= v_coor[0][0])
	{
		v_coor[i][2] = enemy_distance(map, piece, e_coor, v_coor[i]);
		i++;
	}
	best = sort_coor(v_coor);
	free_coor(e_coor);
	//free_coor(v_coor);
	return (best);
}
