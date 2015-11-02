/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 18:01:30 by harar             #+#    #+#             */
/*   Updated: 2015/01/06 11:24:55 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE	0x2323

typedef struct		s_gnlp
{
	int				fd;
	char			*buf;
	struct s_gnlp	*next;
}					t_gnlp;

int					get_next_line(int const fd, char **line);

#endif
