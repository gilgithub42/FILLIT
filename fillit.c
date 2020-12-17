/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: team <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:27:57 by team              #+#    #+#             */
/*   Updated: 2020/08/27 17:28:03 by team             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int				tetnb;
	t_tetriminos	tetri[26];

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	tetnb = ft_load_tetriminos(av[1], tetri);
	if (tetnb == -1)
	{
		ft_putstr("error\n");
		return (1);
	}
	fillit(tetri, tetnb);
	return (0);
}
