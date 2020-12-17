/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchadir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 21:16:34 by kchadir           #+#    #+#             */
/*   Updated: 2019/12/23 21:16:59 by kchadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_firstchar(char const *s, char c, int i)
{
	int	ifc;

	if (i == 0)
		ifc = (s[0] != c) ? 1 : 0;
	else
		ifc = (s[i] != c && s[i - 1] == c) ? 1 : 0;
	return (ifc);
}

static int	nbr_words(char const *s, char c)
{
	int	i;
	int	nw;

	i = -1;
	nw = 0;
	while (s[++i])
		nw += is_firstchar(s, c, i);
	return (nw);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	str;
	size_t	flg;
	size_t	iw;
	char	**split;

	i = -1;
	flg = 0;
	iw = -1;
	if (!s)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char *) * nbr_words(s, c) + 1)))
		return (NULL);
	while (s[++i])
	{
		flg = (is_firstchar(s, c, i) == 1) ? 1 : flg;
		str = (is_firstchar(s, c, i) == 1) ? i : str;
		if (flg == 1 && s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			if ((split[++iw] = ft_strnew(i - str + 1)) && !(flg *= 0))
				split[iw] = ft_strsub(s, str, i - str + 1);
	}
	split[++iw] = NULL;
	return (split);
}
