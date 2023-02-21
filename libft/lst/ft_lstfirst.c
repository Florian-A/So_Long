/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:09:35 by f██████           #+#    #+#             */
/*   Updated: 2023/02/21 01:07:54 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstfirst(t_list *lst)
{
	int		i;
	t_list	*lst1;

	if (lst != NULL)
	{
		i = 1;
		lst1 = lst;
		while (lst1->previous != NULL)
		{
			lst1 = lst1->previous;
			i++;
		}
		return (lst1);
	}
	else
		return (0);
}
