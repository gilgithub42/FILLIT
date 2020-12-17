/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchadir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:06:43 by kchadir           #+#    #+#             */
/*   Updated: 2019/11/21 13:10:42 by kchadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	chr;

	i = -1;
	chr = (unsigned char)c;
	tmp = (unsigned char *)s;
	while (++i < n)
		if (tmp[i] == chr)
			return ((void *)(s + i));
	return (NULL);
}
