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
	char	*tmp;
	char	*line;

	if (get_next_line(0, &line) < 0)
		return (0);
	tmp = line;
	while (!ft_isdigit(*line))
		line++;
	piece->height = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	piece->width = ft_atoi(line);
	free(tmp);
	return (1);
}

int		fill_piece(t_piece *piece)
{
	char	*line;
	int		i;

	if (!(fill_metadata(piece)))
		return (0);
	if (!(piece->content = init_map(piece->height, piece->width)))
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
	return (1);
}
