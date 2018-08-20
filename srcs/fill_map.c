/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:56:58 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/20 18:49:17 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/filler.h"

int		get_map_size(t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	if(get_next_line(0, &line) < 0)
		return (1);
	while (!(ft_isdigit(line[i])))
		i++;
	map->height = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	map->width = ft_atoi(&line[i]);
	printf("%d", map->height);
	printf("%d", map->width);
	free(line);
	return (0);
}

int		get_map_content(t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	if(get_next_line(0, &line) < 0)
		return (1);
	free(line);
	while (i < map->height)
	{
		if(get_next_line(0, &(map->content[i]) ) < 0)
			return (1);
		map->content[i]= map->content[i] + 4;
		i++;
	}
	free(line);
	return (0);
}

int		fill_map(t_map *map)
{
	if (get_map_size(map))
		return (1);
	if(!(map->content = init_map(map->height, map->width)))
		return (1);
	if (get_map_content(map))
		return (1);
	return (0);
}