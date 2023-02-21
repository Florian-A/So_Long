/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arradd_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:09:35 by f██████           #+#    #+#             */
/*   Updated: 2023/02/21 01:07:54 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	void	*cleaning(char **arr)
{
	ft_arr2dfree((void **)arr);
	return (NULL);
}

char	**ft_arradd_str(char **arr, char *str)
{
	int		i;
	int		len;
	char	**new_arr;

	i = 0;
	if (arr == NULL)
		len = 0;
	else
		len = ft_arr2dlen((void **)arr);
	new_arr = ft_calloc(len + 2, sizeof(char *));
	if (!new_arr)
		return (NULL);
	while (i < len)
	{
		new_arr[i] = ft_strdup(arr[i]);
		if (new_arr[i] == NULL)
			return (cleaning(new_arr));
		i++;
	}
	new_arr[i] = ft_strdup(str);
	if (new_arr[i] == NULL)
		return (cleaning(new_arr));
	return (new_arr);
}
