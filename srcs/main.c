/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:22:25 by vduong            #+#    #+#             */
/*   Updated: 2018/08/20 19:05:27 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/filler.h"


int	main()
{
	t_player			player;
	t_map				map;
	t_piece				piece;
	char				*firstline;
	int error;
	int	i;

	i = 0;
	error = 0;
	get_next_line(0, &firstline);
	printf("line = %s\n", firstline);
	if (strstr(firstline, "$$$"))
		fill_player(&player, firstline);
	printf("Player name = %s, player number = %d, player symbol = %c\n",
			player.name, player.number, player.symbol);
	while (1)
	{
		if (fill_map(&map))
			break;
		while (map.content[i])
		{
			printf("tintin%s\n", map.content[i]);
			i++;
		}
		if(fill_piece(&piece))
			break;
		i = 0;
		while (piece.content[i])
		{
			printf("tintin%s\n", piece.content[i]);
			i++;
		}
			break;
/*		if(!(algo(...)))*/
			break;
	}
	return (0);
}
