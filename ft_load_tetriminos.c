/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ree.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team    <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:29:11 by team              #+#    #+#             */
/*   Updated: 2020/08/29 17:32:14 by team             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_minmax(t_tetriminos *tetri, int tetnb, int lc, char *c)
{
	int		i;
	int		res;

	i = 0;
	res = tetri[tetnb].pos[i][lc];
	while (++i < 4)
	{
		if (ft_strcmp(c, "MIN") == 0)
			res = (res > tetri[tetnb].pos[i][lc]) ? \
				tetri[tetnb].pos[i][lc] : res;
		else if (ft_strcmp(c, "MAX") == 0)
			res = (res < tetri[tetnb].pos[i][lc]) ? \
				tetri[tetnb].pos[i][lc] : res;
	}
	return (res);
}

static int	ft_get_tetri_position(char *line, t_idx *idx, t_tetriminos *tetri)
{
	int		i;

	i = -1;
	((*idx).linenb)++;
	if ((*idx).linenb % 5 != 0)
		while (line[++i])
		{
			if (line[i] == '#')
			{
				((*idx).cnt)++;
				if ((*idx).cnt > 4)
					return (-1);
				tetri[(*idx).tetnb].pos[(*idx).cnt - 1][0] = (*idx).linenb % 5;
				tetri[(*idx).tetnb].pos[(*idx).cnt - 1][1] = i;
			}
			else if (line[i] != '.')
				return (-1);
		}
	if (((*idx).linenb % 5 == 0 && line[0] != '\0') || \
			((*idx).linenb % 5 != 0 && i != 4))
		return (-1);
	return (1);
}

static int	ft_tetri_isintouch(t_tetriminos *t, int n)
{
	int		i;
	int		j;
	int		flg;

	i = -1;
	flg = 0;
	while (++i < 4)
	{
		j = 0;
		while (++j < 4)
			if ((t[n].pos[(i + j) % 4][0] == t[n].pos[i][0] - 1 && \
						t[n].pos[(i + j) % 4][1] == t[n].pos[i][1]) || \
					(t[n].pos[(i + j) % 4][0] == t[n].pos[i][0] + 1 && \
					t[n].pos[(i + j) % 4][1] == t[n].pos[i][1]) || \
					(t[n].pos[(i + j) % 4][0] == t[n].pos[i][0] && \
					t[n].pos[(i + j) % 4][1] == t[n].pos[i][1] - 1) || \
					(t[n].pos[(i + j) % 4][0] == t[n].pos[i][0] && \
					t[n].pos[(i + j) % 4][1] == t[n].pos[i][1] + 1))
				flg++;
	}
	return (flg < 6 ? -1 : 1);
}

static void	ft_tetri_format(t_tetriminos *tetri, int tetnb)
{
	int		tab[5];

	tab[0] = -1;
	tab[1] = ft_minmax(tetri, tetnb, 0, "MIN");
	tab[2] = ft_minmax(tetri, tetnb, 1, "MIN");
	tab[3] = ft_minmax(tetri, tetnb, 0, "MAX");
	tab[4] = ft_minmax(tetri, tetnb, 1, "MAX");
	while (++tab[0] < 4)
	{
		tetri[tetnb].pos[tab[0]][0] -= tab[1];
		tetri[tetnb].pos[tab[0]][1] -= tab[2];
	}
	tetri[tetnb].lettre = 'A' + tetnb;
	tetri[tetnb].height = tab[3] - tab[1] + 1;
	tetri[tetnb].width = tab[4] - tab[2] + 1;
}

int			ft_load_tetriminos(char *file, t_tetriminos *tetri)
{
	char	*line;
	t_idx	idx;

	if ((idx.fd = open(file, O_RDONLY)) == -1)
		return (-1);
	idx.linenb = 0;
	idx.tetnb = 0;
	idx.cnt = 0;
	while (get_next_line(idx.fd, &line) > 0)
	{
		if (ft_get_tetri_position(line, &idx, tetri) == -1 || idx.tetnb > 26)
			return (-1);
		if (idx.linenb % 5 == 4)
		{
			if (idx.cnt != 4 || ft_tetri_isintouch(tetri, idx.tetnb) == -1)
				return (-1);
			idx.cnt = 0;
			ft_tetri_format(tetri, idx.tetnb);
			idx.tetnb++;
		}
		free(line);
	}
	free(line);
	return (((close(idx.fd) == -1) || (idx.linenb != (idx.tetnb * 5 - 1))) ? \
			-1 : idx.tetnb);
}
