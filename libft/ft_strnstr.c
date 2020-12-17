/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchadir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:43:39 by kchadir           #+#    #+#             */
/*   Updated: 2019/11/20 18:48:15 by kchadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (tofind[i] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		if (str[i] == tofind[0])
		{
			j = 0;
			while (str[i + j] == tofind[j] && i + j < len)
			{
				if (tofind[j + 1] == '\0')
					return ((char *)(str + i));
				j++;
			}
		}
		i++;
	}
	return (0);
}
