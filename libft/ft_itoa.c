/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchadir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:27:36 by kchadir           #+#    #+#             */
/*   Updated: 2019/12/03 21:14:33 by kchadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t		i;
	long int	ln;
	char		*str;

	i = ((long int)n < 0) ? 1 : 0;
	ln = ((long int)n < 0) ? (long int)n * -1 : n;
	while (ln > 9)
	{
		ln /= 10;
		i++;
	}
	if (!(str = ft_strnew(++i)))
		return (NULL);
	ln = ((long int)n < 0) ? (long int)n * -1 : n;
	while (i-- > 0)
		if (i == 0 && n < 0)
			str[i] = '-';
		else
		{
			str[i] = ln % 10 + '0';
			ln /= 10;
		}
	return (str);
}
