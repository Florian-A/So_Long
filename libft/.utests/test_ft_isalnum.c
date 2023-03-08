/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ███████ <███████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by ███████           #+#    #+#             */
/*   Updated: 2022/05/10 11:06:54 by ███████          ###   ########lyon.fr   */
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
