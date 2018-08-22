/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:29:51 by vduong            #+#    #+#             */
/*   Updated: 2018/08/21 15:14:06 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char	**init_map(int height, int width)
{
	int		i;
	char	**map;

	if (!(map = (char **)(malloc(sizeof(char*) * (height + 1)))))
		return (NULL);
	map[height] = NULL;
	i = 0;
	while (i < height)
	{
		if (!(map[i] = ft_strnew(width)))
			return (NULL);
		i++;
	}
	return (map);
}
