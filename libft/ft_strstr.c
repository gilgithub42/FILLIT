/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchadir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:22:03 by kchadir           #+#    #+#             */
/*   Updated: 2019/11/20 18:49:00 by kchadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *tofind)
{
	int	i;
	int	j;

	i = 0;
	if (tofind[i] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		if (str[i] == tofind[0])
		{
			j = 0;
			while (str[i + j] == tofind[j])
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
