/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:28:34 by team              #+#    #+#             */
/*   Updated: 2020/08/29 17:11:23 by team             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**tetri_map_create(int size)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	if (!(map = (char **)ft_memalloc(sizeof(*map) * (size + 1))))
		return (NULL);
	while (++i < size)
	{
		if (!(map[i] = (char *)ft_strnew(sizeof(**map) * (size))))
			return (NULL);
		j = -1;
		while (++j < size)
			map[i][j] = '.';
	}
	return (map);
}

void	tetri_map_free(char **map, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		ft_memdel((void **)&(map[i]));
	ft_memdel((void **)&map);
}

void	tetri_map_print(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
		ft_putendl(map[i++]);
}
