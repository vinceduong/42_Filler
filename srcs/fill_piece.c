/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:41:53 by vduong            #+#    #+#             */
/*   Updated: 2018/09/17 15:42:34 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fill_metadata(t_piece *piece)
{
	char	*line;
	char	*tmp;
	int		i;

	if (get_next_line(0, &line) < 0)
		return (0);
	tmp = line;
	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	piece->height = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	piece->width = ft_atoi(&line[i]);
	free(tmp);
	return (1);
}

int		fill_index(t_piece *piece)
{
	int i;
	int j;

	i = 0;
	while (i < piece->height)
	{
		j = 0;
		while (j < piece->width)
		{
			if (piece->content[i][j] == '*')
			{
				piece->h_index = i;
				piece->w_index = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		fill_piece(t_piece *piece)
{
	char	*line;
	int		i;

	if (!(fill_metadata(piece)))
		return (0);
	if (!(piece->content = init_map(piece->height)))
		return (0);
	i = 0;
	while (i < piece->height)
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		piece->content[i] = ft_strdup(line);
		free(line);
		i++;
	}
	fill_index(piece);
	return (1);
}
