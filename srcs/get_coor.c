/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:52:25 by vduong            #+#    #+#             */
/*   Updated: 2018/08/21 15:09:09 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

#define  PCONTENT piece.content[y][x]
#define  MCONTENT map.content[i + y][j + x]

int		is_placable(t_map map, t_piece piece, char symbol, int i, int j)
{
	int	nbover;
	int	x;
	int y;

	nbover = 0;
	y = 0;
	while (y < piece.height)
	{
		x = 0;
		while (x < piece.width)
		{
			if (PCONTENT == '*' && ((i + y >= map.height) || j + x >= map.width))
				return (0);
			if (PCONTENT == '*' && MCONTENT == symbol)
				nbover++;
			if (PCONTENT == '*' && MCONTENT != '.' && MCONTENT != symbol)
				return (0);
			x++;
		}
		y++;
	}
	return (nbover == 1);
}

int		count_placable_coor(t_map map, t_piece piece, char symbol)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			count += is_placable(map, piece, symbol, i, j);
			j++;
		}
		i++;
	}
	ft_putstr("okcount\n");
	printf ("count = %d\n", count);
	return (count);
}

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
			printf("OK\n");
			i++;
		}
	}
	return (coor);
}

int		**get_coor(t_map map, t_piece piece, char symbol)
{
	int		**coor;
	int		i;
	int		j;
	int		nb;

	ft_putstr("ok1\n");
	if (!(coor = init_coor(count_placable_coor(map, piece, symbol))))
		return (NULL);
	ft_putstr("ok2\n");
	nb = 1;
	printf("height  = %d\n", map.height);
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (is_placable(map, piece, symbol, i, j))
			{
				printf("is placable, nb = %d\n", nb);
				coor[nb][0] = i;
				coor[nb][1] = j;
				ft_putstr("ok3\n");
				nb++;
			}
			j++;
		}
		i++;
	}
	ft_putstr("ok3\n");
	return (coor);
}
