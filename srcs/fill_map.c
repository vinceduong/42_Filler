/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:56:58 by carmenia          #+#    #+#             */
/*   Updated: 2018/09/17 15:42:14 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_map_size(t_map *map)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line) <= 0)
		return (0);
	tmp = line;
	while (!(ft_isdigit(*line)))
		line++;
	map->height = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	map->width = ft_atoi(line);
	free(tmp);
	return (1);
}

int		get_map_content(t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	if (get_next_line(0, &line) < 0)
		return (0);
	free(line);
	while (i < map->height)
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		map->content[i] = ft_strdup(line + 4);
		free(line);
		i++;
	}
	return (1);
}

int		fill_map(t_map *map)
{
	if (!get_map_size(map))
		return (0);
	if (!(map->content = init_map(map->height)))
		return (0);
	if (!get_map_content(map))
		return (0);
	return (1);
}
