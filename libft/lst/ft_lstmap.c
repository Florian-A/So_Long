/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                               		    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:09:35 by f██████           #+#    #+#             */
/*   Updated: 2021/11/03 10:30:00 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;

	if (!lst || !f)
		return (NULL);
	lst1 = lst;
	lst2 = ft_lstnew(f(lst->content));
	if (!lst2)
		return (NULL);
	while (lst1->next)
	{
		lst3 = ft_lstnew(f(lst1->next->content));
		if (!lst3)
		{
			ft_lstclear(&lst2, del);
			return (NULL);
		}
		ft_lstadd_back(&lst2, lst3);
		lst1 = lst1->next;
	}
	return (lst2);
}
