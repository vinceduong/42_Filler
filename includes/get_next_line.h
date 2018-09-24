/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:58:04 by carmenia          #+#    #+#             */
/*   Updated: 2018/09/24 14:56:19 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8
# include "libft.h"

typedef struct	s_file
{
	int					fd;
	struct s_file		*next;
	char				*read;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif
