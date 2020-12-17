/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchadir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:15:14 by kchadir           #+#    #+#             */
/*   Updated: 2019/12/04 13:41:35 by kchadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*map;

	i = -1;
	if (!s)
		return (NULL);
	if (!(map = ft_strdup(s)))
		return (NULL);
	while (map[++i])
		map[i] = f(map[i]);
	return (map);
}
