/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchadir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:09:25 by kchadir           #+#    #+#             */
/*   Updated: 2019/12/05 16:23:30 by kchadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lstitr;
	t_list *elt2free;

	lstitr = *alst;
	while (lstitr)
	{
		elt2free = lstitr;
		ft_lstdelone(&elt2free, del);
		lstitr = lstitr->next;
	}
	*alst = NULL;
}
