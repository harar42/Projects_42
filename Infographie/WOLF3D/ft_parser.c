/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 10:47:28 by harar             #+#    #+#             */
/*   Updated: 2015/03/03 16:47:57 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_wolf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	ft_getsize(t_env *e, int fd)
{
	int		*size;
	char	*line;

	if (get_next_line(fd, &line) < 1)
		exit(ft_perror("[Parser]: Le fichier est vide."));
	size = ft_intsplit(line, ' ');
	e->map.x = size[0];
	e->map.y = size[1];
	e->player.pos.x = size[2];
	e->player.pos.y = size[3];
}

static void ft_getmap(t_env *e, int fd)
{
	char		*line;
	int			**map;
	static int	i;

	if ((map = (int **)malloc(sizeof(int *) * e->map.x)) == NULL)
		exit(ft_perror("[Parser]: Allocation impossible."));
	while (get_next_line(fd, &line) > 0)
		map[i++] = ft_intsplit(line, ' ');
	e->map.map = map;
}

void		ft_parser(char *file, t_env *e)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		exit(ft_perror("Le fichier est introuvable."));
	ft_getsize(e, fd);
	ft_getmap(e, fd);
	close(fd);
}
