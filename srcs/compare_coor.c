/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_coor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 10:57:34 by vduong            #+#    #+#             */
/*   Updated: 2018/09/12 07:56:39 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"


int		compare_coor(t_map map, int *c1, int *c2)
{
	/*if ((!c1[3] || !c1[4]) && (!c2[3] || !c2[4]))
		return (0);
	if (!c2[3] || !c2[4])
		return (0);
	if (!c1[3] || !c1[4])
		return (1);*/
	map.height += 0;
	return (c1[2] > c2[2]);
/*if (!c1[2] && c2[2])
		return 1;
	if (c1[2] && !c2[2])
		return 0;
	if (borderdist1 + c1[2] > borderdist2 + c2[2])
		return (1);
	else
		return (0);*/
}
