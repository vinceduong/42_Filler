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
		while (i <= map->height)
		{
			free(map->content[i]);
			i++;
		}
		free(map->content);
		ft_bzero(map, sizeof(t_map));
	}
}

void	free_piece(t_piece *piece)
{
	int i;

	i = 0;
	if (piece)
	{
		while (i <= piece->height)
		{
			free(piece->content[i]);
			i++;
		}
		free(piece->content);
		ft_bzero(piece, sizeof(t_piece));
	}
}

void	free_all(t_map *map, t_piece *piece)
{
	if (map)
		free_map(map);
	if (piece)
		free_piece(piece);
}
