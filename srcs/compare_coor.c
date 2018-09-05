/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_coor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 10:57:34 by vduong            #+#    #+#             */
/*   Updated: 2018/09/05 15:33:17 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"


int		compare_coor(int *c1, int *c2)
{
	int borderdist1;
	int borderdist2;

	borderdist1 = c1[3] > c1[4] ? c1[3] : c1[4];
	borderdist2 = c2[3] > c2[4] ? c2[3] : c2[4];
	if (!c1[2] && c2[2])
		return 1;
	if (c1[2] && !c2[2])
		return 0;
	if (borderdist1 + c1[2] > borderdist2 + c2[2])
		return (1);
	else
		return (0);
}
