/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchadir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:58:09 by kchadir           #+#    #+#             */
/*   Updated: 2019/12/06 21:56:46 by kchadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *lstnew)
{
	t_list	*lsttmp;

	if (!*alst)
		*alst = lstnew;
	else
	{
		lsttmp = *alst;
		while (lsttmp->next)
			lsttmp = lsttmp->next;
		lsttmp->next = lstnew;
	}
}
