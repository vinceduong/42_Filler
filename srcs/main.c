/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:22:25 by vduong            #+#    #+#             */
/*   Updated: 2018/08/21 15:14:24 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/filler.h"


int	main()
{
	t_player			player;
	t_map				map;
	t_piece				piece;
	char				*firstline;

	int					**coor;
	get_next_line(0, &firstline);
	if (strstr(firstline, "$$$"))
		fill_player(&player, firstline);
	while (1)
	{
		if (fill_map(&map) == 1)
			break;
		if (fill_piece(&piece) == 1)
			break;
		coor = get_coor(map, piece, player.symbol);
		int i;
		i = 1;
		printf("Il y a %d coordonnees possibles : \n", coor[0][0]);
		while (i < coor[0][0] + 1)
		{
			printf("Coordonee %2d : %2d - %2d\n", i, coor[i][0], coor[i][1]);
			i++;
		}
		//sleep(44444000);
		/*if (write_coor(map, piece, player) == 1)
			break;
		free_map(&map);
		free_piece(&piece);*/
	}
	//free_player(&player);
	return (0);
}
