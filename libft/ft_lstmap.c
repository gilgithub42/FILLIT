/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchadir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:07:26 by kchadir           #+#    #+#             */
/*   Updated: 2019/12/06 23:08:45 by kchadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newelt;
	t_list	*lstres;
	t_list	*tmp;

	tmp = f(lst);
	if (!(newelt = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	lstres = newelt;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(newelt->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		newelt = newelt->next;
		lst = lst->next;
	}
	return (lstres);
}
