/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchadir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 20:57:51 by kchadir           #+#    #+#             */
/*   Updated: 2019/12/05 16:37:17 by kchadir          ###   ########.fr       */
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

t_list		*ft_lststrsplit(char const *s, char c)
{
	size_t	i;
	size_t	str;
	size_t	flg;
	t_list	*split;

	i = -1;
	flg = 0;
	split = NULL;
	while (s[++i])
	{
		flg = (is_firstchar(s, c, i) == 1) ? 1 : flg;
		str = (is_firstchar(s, c, i) == 1) ? i : str;
		if (flg == 1 && s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			flg = 0;
			if (split == NULL)
				split = ft_lstnew(ft_strsub(s, str, i - str + 1), i - str + 1);
			else
				ft_lstadd_back(&split, ft_lstnew(ft_strsub(s, str, \
									i - str + 1), i - str + 1));
		}
	}
	return (split);
}
