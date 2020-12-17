/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchadir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:28:51 by kchadir           #+#    #+#             */
/*   Updated: 2019/12/05 17:33:26 by kchadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lstbfr;

	if (!lst)
		return (NULL);
	while (lst)
	{
		lstbfr = lst;
		lst = lst->next;
	}
	return (lstbfr);
}
