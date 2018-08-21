/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:22:25 by vduong            #+#    #+#             */
/*   Updated: 2018/08/20 19:07:57 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/filler.h"


int	main(int argc, char **argv)
{
	t_player			player;
	t_map				map;
	t_piece				piece;
	char				*firstline;

	get_next_line(0, &firstline);
	if (strstr(firstline, "$$$"))
		fill_player(&player, firstline);
	while (1)
	{
		if (!(fill_map(&map)))
			break;
		if(!(fill_piece(&piece)))
			break;
/*		if(!(algo(...)))*/
			break;
	}
	return (0);
}
