/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_coor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:38:39 by vduong            #+#    #+#             */
/*   Updated: 2018/09/05 14:36:16 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int **sorted_coor(t_map map, t_piece piece, char symbol)
{
	int **v_coor;
	int **e_coor;
	int *tmp;
	int	i;

	if (!(v_coor = get_valid_coor(map, piece, symbol)) || !v_coor[0][0])
		return (NULL);
	if (!(e_coor = get_player_coor(map, symbol == 'O' ? 'X' : 'O')))
		return (NULL);
	i = 1;
	//printf("%d\n", v_coor[0][0]);
	while (i <= v_coor[0][0])
	{
		v_coor[i][2] = enemy_distance(map, piece, e_coor, v_coor[i]);
		tmp = border_distance(map, piece, e_coor, v_coor[i]);
		/*printf("tmp[0] = %d\n", tmp[0]);
		printf("tmp[1] = %d\n", tmp[1]);*/
		v_coor[i][3] = tmp[0];
		v_coor[i][4] = tmp[1];
		//printf("i = %d, j = %d, distance = %d\n", v_coor[i][0], v_coor[i][1], v_coor[i][3]);
		i++;
	}
	i = 1;
	while (i < v_coor[0][0])
	{
		if (compare_coor(v_coor[i], v_coor[i + 1]))
		{
			//printf("sorted\n");
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
