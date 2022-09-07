/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <falonso@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by f██████           #+#    #+#             */
/*   Updated: 2022/09/07 12:13:52 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

int	test_ft_strlen(void)
{
	char	*s1;

	s1 = "";
	if (ft_strlen(s1) != 0)
		return (-1);
	s1 = "test";
	if (ft_strlen(s1) != 4)
		return (-1);
	s1 = "pif\0paf";
	if (ft_strlen(s1) != 3)
		return (-1);
	return (0);
}
