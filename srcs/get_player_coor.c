/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_coor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:04:43 by vduong            #+#    #+#             */
/*   Updated: 2018/08/22 16:00:07 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#define	MCONTENT	map.content[i][j]

int		**get_player_coor(t_map map, char symbol)
{
	int	**coor;
	int	i;
	int	j;
	int nb;

	if (!(coor = init_coor(count_symbol(map, symbol))))
		return (NULL);
	nb = 1;
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (MCONTENT == symbol || MCONTENT == (symbol == 'O' ? 'o' : 'x'))
			{
				coor[nb][0] = i;
				coor[nb][1] = j;
				//printf("i = %d, j = %d\n", coor[nb][0], coor[nb][1]);
				nb++;
			}
			j++;
		}
		i++;
	}
	return (coor);
}
