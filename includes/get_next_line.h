/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:58:04 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/20 12:58:23 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8
# include "../libft/libft.h"

typedef struct	s_file
{
	int					fd;
	struct s_file		*next;
	char				*read;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif
