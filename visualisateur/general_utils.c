/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:54:08 by vduong            #+#    #+#             */
/*   Updated: 2018/09/26 12:54:09 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler_viz.h"

int			idx(int row, int col, int dim)
{
	return (row * dim + col);
}

char		*board_strdup(t_game *game, int i, const char *s)
{
	char	*new_s;
	char	*start;
	size_t	len;
	size_t	j;

	len = ft_strlen(s);
	if ((new_s = (char *)malloc((len + 1) * sizeof(*new_s))) != NULL)
	{
		new_s[len] = '\0';
		start = new_s;
		j = 0;
		while (j < len)
		{
			*new_s = *s;
			if (*s == 'o' || *s == 'x')
				game->color_t_rt[idx(i, (int)j, game->w)] = game->gss->turn;
			new_s++;
			s++;
			j++;
		}
		return (start);
	}
	return (NULL);
}
