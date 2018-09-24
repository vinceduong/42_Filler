/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:14:47 by vduong            #+#    #+#             */
/*   Updated: 2018/09/24 19:18:46 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_map(t_map *map)
{
	int i;

	i = 0;
	if (map)
	{
		while (i < map->height)
		{
			free(map->content[i]);
			i++;
		}
		free(map->content);
	}
}

void	free_piece(t_piece *piece)
{
	int i;

	i = 0;
	if (piece)
	{
		while (i < piece->height)
		{
			free(piece->content[i]);
			i++;
		}
		free(piece->content);
	}
}

void	free_coor(int **coor)
{
	int i;
	int n;

	i = 1;
	n = coor[0][0];
	if (coor)
	{
		while (i < n)
		{
			free(coor[i]);
		}
		free(coor);
	}
}

void	free_all(t_map *map, t_piece *piece)
{
	free_map(map);
	free_piece(piece);
}
