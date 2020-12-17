/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchadir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:01:06 by kchadir           #+#    #+#             */
/*   Updated: 2019/12/04 13:42:25 by kchadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*map;

	i = -1;
	if (!s)
		return (NULL);
	if (!(map = ft_strdup(s)))
		return (NULL);
	while (map[++i])
		map[i] = f(i, map[i]);
	return (map);
}
