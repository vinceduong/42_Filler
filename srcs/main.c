/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:22:25 by vduong            #+#    #+#             */
/*   Updated: 2018/08/22 18:46:38 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/filler.h"


int	main()
{
	t_player			player;
	t_map				map;
	t_piece				piece;
	char				*line;
	int					**coor;

	if (get_next_line(0, &line) && line && ft_strlen(line) > 10 &&
			            !ft_strncmp(line, "$$$ exec p", 9) &&
						            (line[10] == '1' || line[10] == '2'))
		fill_player(&player, line);
	while (1)
	{
		if (fill_map(&map) == 1)
		{
			break;
		}
		if (fill_piece(&piece) == 1)
		{
			break;
		}
		coor = sorted_coor(map, piece, player.symbol);
		printf("%d %d\n", coor[1][0], coor[1][1]);
	}
	return (0);
}
