/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchadir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:23:23 by kchadir           #+#    #+#             */
/*   Updated: 2019/11/25 17:49:22 by kchadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, \
					int c, size_t n)
{
	size_t			i;
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;
	unsigned char	chr;

	i = -1;
	chr = (unsigned char)c;
	tmpdst = (unsigned char *)dst;
	tmpsrc = (unsigned char *)src;
	while (++i < n)
	{
		tmpdst[i] = tmpsrc[i];
		if (tmpdst[i] == chr)
			return ((void *)(dst + i + 1));
	}
	return (NULL);
}
