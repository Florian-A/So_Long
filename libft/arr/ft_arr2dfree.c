/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr2dfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <falonso@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:09:35 by f██████           #+#    #+#             */
/*   Updated: 2022/09/07 12:13:52 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_arr2dfree(void **arr)
{
	int	arr_len;
	int	i;

	arr_len = ft_arr2dlen((void **)arr);
	i = 0;
	while (i < arr_len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
