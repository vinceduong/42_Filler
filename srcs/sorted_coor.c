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



int	**sort_coor(int **v_coor)
{
	int i;
	int *tmp;

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
	return (v_coor);
}

int	**sorted_coor(t_map map, t_piece piece, char symbol)
{
	int **v_coor;
	int **e_coor;
	int	i;

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
	free_coor(e_coor);
	return (sort_coor(v_coor));
}
