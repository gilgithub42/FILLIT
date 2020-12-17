/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_map_filler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:28:26 by team              #+#    #+#             */
/*   Updated: 2020/08/27 17:28:29 by team             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void	map_place_tetri(t_tetriminos *tetri, char **map, int lin, int col)
{
	int		i;

	i = -1;
	while (++i < 4)
		map[lin + tetri->pos[i][0]][col + tetri->pos[i][1]] = tetri->lettre;
}

static int	map_check_place_tetri(t_tetriminos *tetri, char **map, \
									int lin, int col)
{
	int		i;

	i = -1;
	while (++i < 4)
		if (map[lin + tetri->pos[i][0]][col + tetri->pos[i][1]] != '.')
			return (0);
	map_place_tetri(tetri, map, lin, col);
	return (1);
}

static void	map_sup_tetri(t_tetriminos *tetri, char **map, int lin, int col)
{
	char	c;

	c = tetri->lettre;
	tetri->lettre = '.';
	map_place_tetri(tetri, map, lin, col);
	tetri->lettre = c;
}

static int	map_set_tetri(char **map, t_tetriminos *tetri, int size, int tetnb)
{
	int		lin;
	int		col;

	lin = 0;
	if (tetri->lettre < 'A' || tetri->lettre > 'Z')
		return (1);
	while (lin <= size - tetri->height)
	{
		col = 0;
		while (col <= size - tetri->width)
		{
			if (map_check_place_tetri(tetri, map, lin, col))
			{
				if (map_set_tetri(map, tetri + 1, size, tetnb))
					return (1);
				else
					map_sup_tetri(tetri, map, lin, col);
			}
			col++;
		}
		lin++;
	}
	return (0);
}

void		fillit(t_tetriminos *tetri, int tetnb)
{
	char	**map;
	int		size;

	size = 2;
	while (size * size < tetnb * 4)
		size++;
	map = tetri_map_create(size);
	while (!map_set_tetri(map, tetri, size, tetnb))
	{
		tetri_map_free(map, size);
		size++;
		map = tetri_map_create(size);
	}
	tetri_map_print(map, size);
	tetri_map_free(map, size);
}
