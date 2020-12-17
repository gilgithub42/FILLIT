/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchadir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:07:38 by kchadir           #+#    #+#             */
/*   Updated: 2020/02/04 20:43:00 by kchadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_posbacslash(char *str)
{
	unsigned	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static int			ft_bufcut(char **str)
{
	if (ft_strchr(*str, '\n'))
	{
		ft_strcpy(*str, ft_strchr(*str, '\n') + 1);
		return (1);
	}
	if (*str[0])
	{
		*str[0] = '\0';
		return (1);
	}
	ft_strdel(str);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int			rd;
	char		*buff;
	char		*ptr;
	static char	*cumbuf[256];

	if (fd < 0 || BUFF_SIZE < 1 || !line || !(buff = ft_strnew(BUFF_SIZE)) ||
		(!cumbuf[fd] && !(cumbuf[fd] = ft_strnew(0))))
		return (-1);
	if (read(fd, buff, 0) < 0)
	{
		free(buff);
		return (-1);
	}
	while (!(ft_strchr(cumbuf[fd], '\n')) &&
			((rd = read(fd, buff, BUFF_SIZE)) > 0))
	{
		buff[rd] = '\0';
		ptr = cumbuf[fd];
		cumbuf[fd] = ft_strjoin(ptr, buff);
		ft_strdel(&ptr);
	}
	ft_strdel(&buff);
	*line = ft_strsub(cumbuf[fd], 0, ft_posbacslash(cumbuf[fd]));
	return (ft_bufcut(&cumbuf[fd]));
}
