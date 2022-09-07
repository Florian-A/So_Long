/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <falonso@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2022/09/07 12:13:52 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

int	test_ft_isalnum(void)
{
	char	s1[61];
	int		i;

	ft_strlcpy(s1, \
	"ABCDEFHIJKLMNOPQRSTUVWYZabcdefghijklmnopkrstuvwxyz0123456789", 61);
	i = 0;
	while (i < 60)
	{
		if (ft_isalnum(s1[i]) != 1)
			return (-1);
		i++;
	}
	ft_strlcpy(s1, "`@[{}\201", 7);
	i = 0;
	while (i < 7)
	{
		if (ft_isalnum(s1[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}
