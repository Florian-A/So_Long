/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_arradd_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ███████ <███████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by ███████           #+#    #+#             */
/*   Updated: 2022/07/29 05:19:22 by ███████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

int	test_ft_arradd_str(void)
{
	char	*s1;
	char	**arr1;
	char	**arr2;

	s1 = ft_strdup("this is a");
	if (!s1)
		return (-1);
	arr1 = ft_split(s1, ' ');
	free(s1);
	arr2 = arr1;
	arr1 = ft_arradd_str(arr1, "test");
	ft_arr2dfree((void **)arr2);
	if (ft_strcmp(arr1[3], "test") != 0)
		return (-1);
	ft_arr2dfree((void **)arr1);
	return (0);
}
