/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchadir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:22:43 by kchadir           #+#    #+#             */
/*   Updated: 2019/12/04 12:34:06 by kchadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;
	char	*tmpdst;
	char	*tmpsrc;

	i = -1;
	if (src == NULL && dst == NULL)
		return (NULL);
	tmpdst = (char *)dst;
	tmpsrc = (char *)src;
	while (++i < n)
		tmpdst[i] = tmpsrc[i];
	dst = (void *)tmpdst;
	return (dst);
}
