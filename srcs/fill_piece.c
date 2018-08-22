/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:41:53 by vduong            #+#    #+#             */
/*   Updated: 2018/08/22 16:39:15 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	fill_metadata(t_piece *piece, char *line)
{
	while (!ft_isdigit(*line))
		line++;
	piece->height = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	piece->width = ft_atoi(line);
}

int		fill_piece(t_piece *piece)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) < 0)
		return(1);
	fill_metadata(piece, line);
	if (!(piece->content = init_map(piece->height, piece->width)))
		return (1);
	i = 0;
	while (i < piece->height)
	{
		if (get_next_line(0, &piece->content[i]) < 0)
			return (1);
		i++;
	}
	return (0);
}
