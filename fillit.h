/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 20:08:34 by team              #+#    #+#             */
/*   Updated: 2020/08/27 20:08:37 by team             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/includes/libft.h"
# include <fcntl.h>

typedef	struct	s_tetriminos
{
	char		lettre;
	int			height;
	int			width;
	int			pos[4][2];
}				t_tetriminos;

typedef	struct	s_idx
{
	int			fd;
	int			linenb;
	int			tetnb;
	int			cnt;
}				t_idx;

void			fillit(t_tetriminos *tetri, int tetnb);
int				ft_load_tetriminos(char *file, t_tetriminos *tetri);
void			tetri_map_print(char **map, int size);
char			**tetri_map_create(int size);
void			tetri_map_free(char **map, int size);

#endif
