/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:14:08 by vduong            #+#    #+#             */
/*   Updated: 2018/08/22 16:00:36 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		**init_coor(int nb)
{
	int	**coor;
	int	i;

	if (!(coor = (int **)malloc(sizeof(int *) * (nb + 2))))
		return (NULL);
	coor[0] = (int *)malloc(sizeof(int *));
	coor[0][0] = nb;
	coor[nb + 1] = NULL;
	if (nb >= 1)
	{
		i = 1;
		while (i < nb + 1)
		{
			if (!(coor[i] = (int *)malloc(sizeof(int) * 2)))
				return (NULL);
			i++;
		}
	}
	return (coor);
}
