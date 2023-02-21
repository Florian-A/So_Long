/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:09:35 by f██████           #+#    #+#             */
/*   Updated: 2023/02/21 01:07:54 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lst_push(t_list *lst, void *content)
{
	t_list	*new_lst;

	if (content == NULL)
		return (NULL);
	if (lst == NULL)
	{
		new_lst = ft_lstnew(content);
		if (new_lst == NULL)
			return (NULL);
	}
	else
	{
		new_lst = ft_lstnew(content);
		if (new_lst == NULL)
			return (NULL);
		ft_lstadd_back(&lst, new_lst);
	}
	new_lst = ft_lstfirst(new_lst);
	return (new_lst);
}
