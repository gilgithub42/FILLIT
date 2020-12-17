/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchadir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:25:59 by kchadir           #+#    #+#             */
/*   Updated: 2019/12/04 12:36:39 by kchadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmpsrc;
	unsigned char	*tmpdst;

	i = -1;
	if (src == NULL && dst == NULL)
		return (NULL);
	tmpsrc = (unsigned char *)src;
	tmpdst = (unsigned char *)dst;
	if (tmpdst > tmpsrc)
		while (0 < len)
		{
			len--;
			tmpdst[len] = tmpsrc[len];
		}
	else
		while (++i < len)
			tmpdst[i] = tmpsrc[i];
	return ((void *)dst);
}
