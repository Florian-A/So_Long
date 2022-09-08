/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2022/09/08 10:48:45 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

int	test_ft_bzero(void)
{
	char	s1[50];
	int		i;

	ft_strlcpy(s1, "ABCDEFHIJKLMNOPQRSTUVWYZabcdefghijklmnopkrstuvwxyz", 50);
	ft_bzero(s1, 0);
	if (s1[0] == 0)
		return (-1);
	ft_bzero(s1, 1);
	if (s1[0] != 0)
		return (-1);
	ft_bzero(s1, 10);
	i = 0;
	while (i < 10)
	{
		if (s1[i] != 0)
			return (-1);
		i++;
	}
	if (s1[9] != 0)
		return (-1);
	if (s1[10] == 0)
		return (-1);
	return (0);
}
